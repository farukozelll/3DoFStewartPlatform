              int rx = A2, ry = A3;
              int lb = 2, rb = 4;
              #define  lb  2 
              #define rb 4
              float buttonstatelb, buttonstaterb;
              int buttonstately, buttonstatelx;
              int buttonstatery, buttonstaterx;          
              float tik=0.0;
              //servo minimum maximum pwm değerleri
              #define MAX 2200
              #define MIN 800
              //bağlantı noktalarının koordinatlarını hesaplamak için gerekli sabitler
              #define pi 3.14159
              #define deg2rad 180/pi
              #define deg30 pi/6
              //Servo dizisi
              Servo servo[6];
              //servoların sıfır pozisyonu yere paralel kollar
              static int zero[6]={1450,1600,1350,1600,1450,1500};
              //Istenen pozisyon dizisi- x,y,z,rot(x),rot(y),rot(z)
              static float arr[6]={0,0.0,0, radians(0),radians(0),radians(0)};
              //Yeni dönme derecesi hesaplama dizisi
              static float theta_a[6]={0.0,0.0,0.0, 0.0,0.0,0.0};
              //Anlık servo pozisyonları
              static int servo_pos[6];
              //X eksenine göre servo kollarının açıları
              const float beta[] = {pi/2,-pi/2,-pi/6, 5*pi/6,-5*pi/6,pi/6};
              //maksimum servo pozisyonları- 0 = yatay
              const float servo_min=radians(-80);
              const float servo_max=radians(80);
              //servo_mult - Radyanı servo pulse değerine çevirme çarpanı
              const float servo_mult=400/(pi/4);
              //L1- Efektif servo kolu uzunluğu, 
              const float L1 = 0.63;
              //L2 - base ve platform bağlama kolu uzunluğu
              const float L2 = 5.70; 
              //z_home - platform base arası yükseklik farkı , 0 = servo kollarının bulunduğu düzlem
              const float z_home = 5.31;
              //RD Platformun merkezinden bağlantı noktasına olan uzaklık
              const float RD = 2.16;
              //PD Base in merkezinden servo kolunun bağlantı noktasına olan uzaklık
              const float PD =2.95;
              //theta_p-iki servo arasındaki açı,
              const float theta_p = radians(37.5); 
              //theta_r - platform bağlantı noktaları arasındaki açı
              const float theta_r = radians(56);
              //theta_angle- yardımcı değer
              const float theta_angle=(pi/3-theta_p)/2;
              //p[][]=servo döndürme noktalarının merkeze göre konumları (x,y)
              const float p[2][6]={
              {-PD*cos(deg30-theta_angle),-PD*cos(deg30-theta_angle),
              PD*sin(theta_angle),PD*cos(deg30+theta_angle),
              PD*cos(deg30+theta_angle),PD*sin(theta_angle)},{
              -PD*sin(deg30-theta_angle),PD*sin(deg30-theta_angle),
              PD*cos(theta_angle),PD*sin(deg30+theta_angle),
              -PD*sin(deg30+theta_angle),-PD*cos(theta_angle)}};
              //re[]{}=x y z platformun bağlantı noktalarının konumları platform merkezine göre (x,y,z)
              const float re[3][6] = {{
              -RD*sin(deg30+theta_r/2),-RD*sin(deg30+theta_r/2),
              -RD*sin(deg30-theta_r/2),RD*cos(theta_r/2),
              RD*cos(theta_r/2),-RD*sin(deg30-theta_r/2),},{
              -RD*cos(deg30+theta_r/2),RD*cos(deg30+theta_r/2),
              RD*cos(deg30-theta_r/2),RD*sin(theta_r/2),
              -RD*sin(theta_r/2),-RD*cos(deg30-theta_r/2),
              },{0,0,0,0,0,0}};
              void setup() {
              pinMode(lb,INPUT);pinMode(rb,INPUT);
              pinMode(ly,INPUT);pinMode(lx,INPUT);
              pinMode(rx,INPUT);pinMode(ry,INPUT);
              digitalWrite(lb, HIGH);digitalWrite(rb, HIGH);
              Serial.begin(9600); 
              // Servo bağlantı pinleri
              servo[0].attach(11, MIN, MAX);servo[1].attach(10, MIN, MAX);
              servo[2].attach(9, MIN, MAX);
              //seri iletişimin başlatılması
              // Sıfır pozisyonuna getirme
              for(int i = 0; i < 6; i++)
              {servo[i].writeMicroseconds(zero[i]);}}
              void loop (){
              buttonstatelb = digitalRead(lb);
              buttonstaterb = digitalRead(rb);
              buttonstately = analogRead(ly);
              buttonstatelx = analogRead(lx);
              buttonstatery = analogRead(ry);
              buttonstaterx = analogRead(rx);
              x=0;y=0;xrot=0;yrot=0;
              if(buttonstatelb==0){
              if(tik<2){tik+=0.01;}}
              if(buttonstaterb==0){
              if(tik>-2){tik-=0.01;}}
              x=map(buttonstaterx,0,1010,-3,3);y=map(buttonstatery,0,1023,-3,3);
              xrot=map(buttonstatelx,0,980,-20,20);yrot=map(buttonstately,0,1004,-20,20);
Serial.println(yrot);
          float pe[6] = {x,y,tik,radians(xrot),radians(yrot),radians(0)},
               theta_a[6],servo_pos[6],
               q[3][6],r[3][6],
               dl[3][6],dl2[6];
                        for(int i = 0; i < 6; i++)
                        {q[0][i] = L1*cos(-theta_a[i])*cos(beta[i]) + p[0][i];
                        q[1][i] = L1*cos(-theta_a[i])*sin(beta[i]) + p[1][i];
                        q[2][i] = -L1*sin(-theta_a[i]);
r[0][i]=re[0][i]*cos(pe[4])*cos(pe[5])+re[1][i]*(sin(pe[3])*sin(pe[4])*cos(pe[5])-cos(pe[3])*sin(pe[5])) + pe[0];
r[1][i]=re[0][i]*cos(pe[4])*sin(pe[5])+re[1][i]*(cos(pe[3])*cos(pe[5])+sin(pe[3])*sin(pe[4])*sin(pe[5])) + pe[1];
r[2][i] = -re[0][i]*sin(pe[4]) + re[1][i]*sin(pe[3])*cos(pe[4]) + z_home + pe[2];
                        dl[0][i] = q[0][i] - r[0][i];dl[1][i] = q[1][i] - r[1][i];
                    dl[2][i] = q[2][i] - r[2][i]; dl2[i] = sqrt(dl[0][i]*dl[0][i] + dl[1][i]*dl[1][i] + dl[2][i]*dl[2][i]) - L2;
                        theta_a[i] += dl2[i];
                        theta_a[i] = constrain(theta_a[i], servo_min, servo_max);
                        if(i%2 == 1) servo_pos[i] = zero[i] + theta_a[i]*servo_mult;
                        else servo_pos[i] = zero[i] - theta_a[i]*servo_mult;
                        }for(int i = 0; i < 6; i++)
                        {servo[i].writeMicroseconds(servo_pos[i]);}}
