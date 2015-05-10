
  float t = 0.0;
  float y[] = {0.0,0.0};//theta, thetadot, the angle and angular velocity of the pendulum
  float E;
  float f0 = 0.0;  //velocity
  float f1 = 0.0;  //accelleration
  float f[] = {0.0,0.0};
  float k1[] = {0.0,0.0};
  float k2[] = {0.0,0.0};
  float k3[] = {0.0,0.0};
  float k4[] = {0.0,0.0};
    

  float theta = 0.0;
  float thetadot = 0.0;
  float force;
      
  float pi = 3.14159;

  float yindex = 0.1;
  float ynext[] = {0.0,0.0};
 
  float gamma = 0.1; 
  float omega0 = 0.72;
  float h = 0.025; //time step in seconds 
  float vibespeed_y = 0.0;
  float vibespeed_x = 0.0;
  float A = 35.0;  
  float resonantf = 1.0;  //Hz
  float drivef = 0.75;
  float resonantomega = 2*pi*resonantf;
  float driveomega = 2*pi*drivef;

  int index=0;

void setup(){
//nothing on this version here  
}

void loop(){

  force = 0;  
  
  k1[0] = getf0(t,y,gamma,resonantomega, driveomega,A,force);
  k1[1] = getf1(t,y,gamma,resonantomega, driveomega,A,force);

  ynext[0] = y[0] + 0.5*h*k1[0];
  ynext[1] = y[1] + 0.5*h*k1[1];
  
  k2[0] = getf0(t+0.5*h,ynext,gamma,resonantomega, driveomega,A,force);
  k2[1] = getf1(t+0.5*h,ynext,gamma,resonantomega, driveomega,A,force);

  ynext[0] = y[0] + 0.5*h*k2[0];
  ynext[1] = y[1] + 0.5*h*k2[1];
  
  k3[0] = getf0(t+0.5*h,ynext,gamma,resonantomega, driveomega,A,force);
  k3[1] = getf1(t+0.5*h,ynext,gamma,resonantomega, driveomega,A,force);

  ynext[0] = y[0] + h*k3[0];
  ynext[1] = y[1] + h*k3[1];

  k4[0] = getf0(t+h,ynext,gamma,resonantomega, driveomega,A,force);
  k4[1] = getf1(t+h,ynext,gamma,resonantomega, driveomega,A,force);
  
  
  ynext[0] = y[0] + 0.1667*h*(k1[0] + 2*k2[0] + 2*k3[0] + k4[0]);
  ynext[1] = y[1] + 0.1667*h*(k1[1] + 2*k2[1] + 2*k3[1] + k4[1]);  


theta = 255.0*abs(y[0])/pi;
thetadot = 255.0*abs(y[1])/pi;
//analogWrite(3,theta);
analogWrite(5,theta);


//wrap the angle around if it goes above or below pi
  if(ynext[0] >= pi){
     ynext[0] = ynext[0] - 2*pi;
  }
  if(ynext[0] <= -pi){
     ynext[0] = ynext[0] + 2*pi;
  }

 
  y[0] = ynext[0];
  y[1] = ynext[1];

  t = t + h;
 
          
 delay(25);

}


float getf0(float t,float y[],float gamma, float resonantomega, float driveomega, float A,float force){
  float result;
  result = y[1];
  return result;
}
float getf1(float t,float y[],float gamma,float resonantomega, float driveomega,float A, float force){
  float result;
  result = -resonantomega*resonantomega*sin(y[0]) - gamma*y[1] + A*cos(driveomega*t) + force;
  return result;
}
