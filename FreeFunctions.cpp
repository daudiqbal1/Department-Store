#include"FreeFunctions.h"


void ClearScreen(){
    system("clear");
};

void Title(){
    cout<<endl;
    cout<<"               ——————————————————————"<<endl;
    cout<<"               BOP2 DEPARTMENT STORE®"<<endl;
    cout<<"               ——————————————————————"<<endl;
};


void ExitApp(){
    ClearScreen();
    cout<<endl<<endl<<"         Terminating the Program";
  
    ClearScreen();
    sleep(1);
    exit(0);
};

int FirstScreen(){
    Title();
    cout<<"--------------------------------------------------"<<endl;
    cout<<"         Welcome to BOP2 Departmental Store       "<<endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<"Enter the store as:"<<endl;
    cout<<"1. Customer"<<endl;
    cout<<"2. StoreKeeper"<<endl<<endl<<endl<<endl<<endl;
    cout<<"Enter your choice:";
    int n;
    cin>>n;
    return n;

};

int CustomerHomeScreen(){
    Title();
    cout<<"--------------------------------------------------"<<endl;
    cout<<"           YOUR FAVORITE SHOPPING PLACE           "<<endl;
    cout<<"--------------------------------------------------"<<endl<<endl<<endl;
    cout<<"Choose your Shopping Department"<<endl<<endl<<endl;
    cout<<"1. Food"<<endl;
    cout<<"2. Garments"<<endl<<endl<<endl;
    cout<<"Enter your choice:";
    int n;
    cin>>n;
    return n;
};

int StoreKeeperHomeScreen(){
    Title();
    cout<<"Choose Desired Operation"<<endl;
    cout<<"1. Sales Report"<<endl;
    cout<<"2. Add Products"<<endl;
    cout<<"3. Delete Products"<<endl;
    cout<<"Enter your choice:";
    int n;
    cin>>n;
    return n;

};