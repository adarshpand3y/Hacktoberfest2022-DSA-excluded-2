#include<iostream>
using namespace std;

int main()
{
  float bmi,weight,height,age;
  cout<<"Please Enter your weight in Pounds : ";
  cin>>weight;
  cout<<"Please Enter your Height in Inches : ";
  cin>>height;
  while(true){
    cout<<"Enter your Age : ";
    cin>>age;
    if(age>=20)
      break;
    else
      cout<<"This Application is only for Adults(20 years old or elder)"<<endl;
      cout<<"Please re-enter your your age to get accurate results!!!"<<endl;
  }
  bmi=(weight*703)/(height*height);
  cout<<"Your BMI is : "<<bmi<<endl;
  if(bmi>=30)
    cout<<"Your BMI value shows that you are obese.";
  else if(bmi>25 && bmi<30)
    cout<<"Your BMI value shows that you are overweight.";
  else if(bmi<25 && bmi>18.5)
    cout<<"Your weight is normal.";
  else
    cout<<"Your BMI value shows that you are underweight.";
  return 0;
}
