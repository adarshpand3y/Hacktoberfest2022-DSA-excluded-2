#include<iostream>
using namespace std;
int main()
{
    int quant;
    int choice;
    //quantity
    int qrooms=0 , qpasta=0, qburger=0, qnoodles=0, qshakes=0, qchicken=0;
    //food item sold
    int srooms=0, spasta=0, sburger=0, snoodles=0, sshake=0, schicken=0;
    //total price of items
    int total_rooms=0, total_pasta=0, total_burger=0, total_noodles=0, total_shake=0, total_chicken=0;

    cout<<"\n\t Quantity of items we have";
    cout<<"\n Rooms available ";
    cin>>qrooms;
    cout<<"\n Quantity of pasta";
    cin>>qpasta;
    cout<<"\n Quantity of burger";
    cin>>qburger;
    cout<<"\n Quantity of noodles";
    cin>>qnoodles;
    cout<<"\n Quantity of shakes";
    cin>>qshakes;
    cout<<"\n Quantity of chicken";
    cin>>qchicken;

     m:
    cout<<"\n\t\t\t please select from given menu options";
    cout<<"\n\n1) Rooms";
    cout<<"\n2) Pasta";
    cout<<"\n3) burger";
    cout<<"\n4) noodles";
    cout<<"\n5) shakes";
    cout<<"\n6) chicken";
    cout<<"\n7) Information regarding sales and colection";
    cout<<"\n8) Exit";

    cout<<"\n\n Please enter your choice";
    cin>>choice;

    switch(choice)
    {
        case 1:
        cout<<"\n\n Enter the number of rooms you want:";
        cin>>quant;
        if(qrooms-srooms >=quant)
        {
          srooms=srooms+quant;
          total_rooms= total_rooms+quant*1200;
          cout<<"\n\n\t\t"<<quant<<"room have been alloted to you";

        }
        else 
        
          cout<<"\n\tonly"<<qrooms-srooms<<"rooms remaining in hotel";
           break;


           case 2:
        cout<<"\n\n Enter the pasta quantity:";
        cin>>quant;
        if(qpasta-spasta >=quant)
        {
          spasta=spasta+quant;
          total_pasta= total_pasta+quant*250;
          cout<<"\n\n\t\t"<<quant<<"pasta is the order";

        }
        else 
        
          cout<<"\n\tonly"<<qpasta-spasta<<"pasta left in hotel";
           break;

           case 3:
        cout<<"\n\n Enter the burger quantity:";
        cin>>quant;
        if(qburger-sburger >=quant)
        {
          sburger=sburger+quant;
          total_burger= total_burger+quant*120;
          cout<<"\n\n\t\t"<<quant<<"burger is the order";

        }
        else 
        
          cout<<"\n\tonly"<<qburger-sburger<<"burgers left in hotel";
           break;


           case 4:
        cout<<"\n\n Enter the noodles quantity:";
        cin>>quant;
        if(qnoodles-snoodles >=quant)
        {
          snoodles=snoodles+quant;
          total_noodles= total_noodles+quant*140;
          cout<<"\n\n\t\t"<<quant<<"noodles is the order";

        }
        else 
        
          cout<<"\n\tonly"<<qnoodles-snoodles<<"noodles left in hotel";
           break;

           case 5:
        cout<<"\n\n Enter the shakes quantity:";
        cin>>quant;
        if(qshakes-sshake >=quant)
        {
          sshake=sshake+quant;
          total_shake= total_shake+quant*120;
          cout<<"\n\n\t\t"<<quant<<"shakes is the order";

        }
        else 
        
          cout<<"\n\tonly"<<qshakes-sshake<<"shakes left in hotel";
           break;


           case 6:
        cout<<"\n\n Enter the chicken quantity:";
        cin>>quant;
        if(qchicken-schicken >=quant)
        {
          schicken=schicken+quant;
          total_chicken= total_chicken+quant*150;
          cout<<"\n\n\t\t"<<quant<<"chicken is the order";

        }
        else 
        
          cout<<"\n\tonly"<<qchicken-schicken<<"chicken left in hotel";
           break;

         

        case 7:
        cout<<"\n\t\tdetails of sales and collection";
        cout<<"\n\n Number of rooms we had:"<<qrooms;
        cout<<"\n\n Number of room we give for rent"<<srooms;
        cout<<"\n\n remaining rooms:"<<qrooms-srooms;
        cout<<"\n\n Total rooms collection for the day:"<< total_rooms;


        cout<<"\n\n quantity of pasta we had:"<<qpasta;
        cout<<"\n\n Number of pasta we sold"<<spasta;
        cout<<"\n\n remaining pasta:"<<qpasta-spasta;
        cout<<"\n\n Total pasta collection for the day:"<< total_pasta;

        cout<<"\n\n quantity of burger we had:"<<qburger;
        cout<<"\n\n Number of burger we sold"<<sburger;
        cout<<"\n\n remaining burger:"<<qburger-sburger;
        cout<<"\n\n Total burger collection for the day:"<< total_burger;
        
        cout<<"\n\n quantity of noodles we had:"<<qnoodles;
        cout<<"\n\n Number of noodles we sold"<<snoodles;
        cout<<"\n\n remaining noodles:"<<qnoodles-snoodles;
        cout<<"\n\n Total noodles collection for the day:"<< total_noodles;

        cout<<"\n\n quantity of shakes we had:"<<qshakes;
        cout<<"\n\n Number of shakes we sold"<<sshake;
        cout<<"\n\n remaining shakes:"<<qshakes-sshake;
        cout<<"\n\n Total shakes collection for the day:"<< total_shake;

        cout<<"\n\n quantity of chicken we had:"<<qchicken;
        cout<<"\n\n Number of chicken we sold"<<schicken;
        cout<<"\n\n remaining chicken:"<<qchicken-schicken;
        cout<<"\n\n Total chicken collection for the day:"<< total_chicken;

        cout<<"\n\n\n toltal collection for the day"<< total_rooms+total_chicken+total_burger+total_noodles+total_shake+total_pasta;
        break;
    
    case 8:
           exit(0);
    default:
           cout<<"\n please select the numbers mentioned above!";
 }
 goto m;


}