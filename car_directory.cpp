#include <iostream>
#include <string.h>
using namespace std; 

struct date {
	int day,month,year;
};
struct car_directory{
	int id;
	string Name,Surname,make,model;
	int phonenum; 
	struct date reg_date,ns_date;
}car[100];
	
	int mark=-1; // like the total number of clients in the directory stored, if we wish to access each of them 
void Add(){
	if(mark>=99){
		cout<<"Sorry, list is Full!"<<endl;
	}
	else {
		mark++;
		cout<<"Please enter the following infos: "<<endl<<"Enter Car's ID: ";
		cin>>car[mark].id;
		cin.ignore();
		cout<<"Enter name: ";
		getline(cin,car[mark].Name); 
		cout<<"Enter surname: ";
		getline(cin,car[mark].Surname);
		cout<<"Enter phone number: ";
		cin>>car[mark].phonenum;
		cout<<"Enter Fabrication: ";
		cin>>car[mark].make;
		cout<<"Enter car model: ";
		cin>>car[mark].model;
		cout<<"Registration day: ";
		cin>>car[mark].reg_date.day;
		cout<<"Registration month: ";
		cin>>car[mark].reg_date.month;
		cout<<"Registration year: ";
		cin>>car[mark].reg_date.year;
		cout<<"Next service day: ";
		cin>>car[mark].ns_date.day;
		cout<<"Next service month: ";
		cin>>car[mark].ns_date.month;
		cout<<"Next service year: ";
		cin>>car[mark].ns_date.year;
		cout<<"Added successful!"<<endl;
	}
}
void deletecar(){
	int deleteid,flag=0;
	cout<<"Please enter the Car ID to delete: ";
	cin>>deleteid;
		for (int i=mark; i<flag;i--){
			if(car[mark].id==deleteid) {
			for(int j=i;j<=mark;j++){
				car[j].id=car[j+1].id;
				car[j].Name=car[j+1].Name;
				car[j].Surname=car[j+1].Surname;
				car[j].phonenum=car[j+1].phonenum;
				car[j].make=car[j+1].make;
				car[j].model=car[j+1].model;
				car[j].reg_date=car[j+1].reg_date;
				car[j].ns_date=car[j+1].ns_date;
				break;
			}
				}
				flag--;
				cout<<"Delete successful!"<<endl;
		} 
		
	if(flag==0){
		cout<<"Person's ID doesn't exist!";
	}
}
void list(){
	cout<<"The info are as follows: "<<endl;
	for(int i=0; i<=mark;i++){
		cout<<(i+1)<<" OWner's infos: "<<endl;
		cout<<"Car's ID: "<<car[i].id<<endl<<"Name: "<<car[i].Name<<endl<<"Surname: "<<car[i].Surname<<endl<<"Phone number: "<<car[i].phonenum<<endl;
		cout<<"Fabrication name: "<<car[i].make<<endl<<"Model name: "<<car[i].model<<endl;
		cout<<"Registration Date: "<<car[i].reg_date.day<<"-"<<car[i].reg_date.month<<"-"<<car[i].reg_date.year<<endl;
		cout<<"Next Service Date: "<<car[i].ns_date.day<<"-"<<car[i].ns_date.month<<"-"<<car[i].ns_date.year<<endl;
	}	
}
void search(){
	int flag=0,option,searchid, reg_year;
	cout<<"Please to search, select between 1 (by ID) or 2 (by registration year): ";
	cin>>option;
	
	if(option==1){
	cout<<"Choice "<<option<<" chosen."<<" Please enter ID: ";
	cin>>searchid;// check this out again, why does i need to enter an id twice before it works?
		} else 
	cout<<"Choice "<<option<<" chosen."<<" Please enter registration year:";
	cin>>reg_year;
	for (int x=0;x<=mark;x++){
	switch(option){
		case 1: 
		if(car[x].id==searchid){
			flag++;
	cout<<"Name: "<<car[x].Name<<endl<<"Surname: "<<car[x].Surname<<endl<<"Phone Number: "<<car[x].phonenum<<endl<<"Fabrication: "<<car[x].make<<endl;
	cout<<"Model: "<<car[x].model<<endl<<"Registration Date: "<<car[x].reg_date.day<<"-"<<car[x].reg_date.month<<"-"<<car[x].reg_date.year<<endl;
	cout<<"Next Service Date: "<<car[x].ns_date.day<<"-"<<car[x].ns_date.month<<"-"<<car[x].ns_date.year<<endl;
		} 
		break;
		case 2:
		 if (car[x].reg_date.year==reg_year){
		 	flag++;
	cout<<"Car ID: "<<car[x].id<<endl;	 	
	cout<<"Name: "<<car[x].Name<<endl<<"Surname: "<<car[x].Surname<<endl<<"Phone Number: "<<car[x].phonenum<<endl<<"Fabrication: "<<car[x].make<<endl;
	cout<<"Model: "<<car[x].model<<endl<<"Registration Date: "<<car[x].reg_date.day<<"-"<<car[x].reg_date.month<<"-"<<car[x].reg_date.year<<endl;
	cout<<"Next Service Date: "<<car[x].ns_date.day<<"-"<<car[x].ns_date.month<<"-"<<car[x].ns_date.year<<endl;
		break;//terminate the line and move forth.
			}
	}
 	}
	if(flag==0){
		cout<<"No record found!"<<endl;
		}
}
void update(){
int counter=0,updateid;
	cout<<"Please enter the car ID to update infos: ";
	cin>>updateid;
		for(int i=0;i<=mark;i++){
			if(car[i].id==updateid){
				counter++; // this is to count each element in the array and check which one is right...
			cout<<"enter new name: ";
			cin>>car[i].Name;
			cout<<"enter new surname: ";
			cin>>car[i].Surname;
			cout<<"enter new Phone number: ";
			cin>>car[i].phonenum;
			cout<<"enter new fabrication name: ";
			cin>>car[i].make;
			cout<<"enter new model name: ";
			cin>>car[i].model;
			cout<<"enter new registration day: ";
			cin>>car[i].reg_date.day;
			cout<<"enter new registration month: ";
			cin>>car[i].reg_date.month;
			cout<<"enter new registration year: ";
			cin>>car[i].reg_date.year;
			cout<<"enter new next service day: ";
			cin>>car[i].ns_date.day;
			cout<<"enter new next service month: ";
			cin>>car[i].ns_date.month;
			cout<<"enter new next service year: ";
			cin>>car[i].ns_date.year;
		cout<<"update successful!"<<endl;
		}
	}
	if(counter==0){
		cout<<"No ID exist!"<<endl;
	}
}
void bubblesort(){
	for (int i=0; i<=mark-1;i++){
		for(int j=0;j<=mark-i-1;j++){
			if(car[j].id>car[j+1].id){
			int swap1=car[j].id;
			car[j].id=car[j+1].id;
			car[j+1].id=swap1;
			string swap2=car[j].Name;
			car[j].Name=car[j+1].Name;
			car[j+1].Name=swap2;
			swap2=car[j].Surname;
			car[j].Surname=car[j+1].Surname;
			car[j+1].Surname=swap2;
			swap1=car[j].phonenum;
			car[j].phonenum=car[j+1].phonenum;
			car[j+1].phonenum=swap1;
			swap2=car[j].make;
			car[j].make=car[j+1].make;
			car[j+1].make=swap2;
			swap2=car[j].model;
			car[j].model=car[j+1].model;
			car[j+1].model=swap2;
			swap1=car[j].reg_date.day;
			car[j].reg_date.day=car[j+1].reg_date.day;
			car[j+1].reg_date.day=swap1;
			swap1=car[j].reg_date.month;
			car[j].reg_date.month=car[j+1].reg_date.month;
			car[j+1].reg_date.month=swap1;
			swap1=car[j].reg_date.month;
			car[j].reg_date.month=car[j+1].reg_date.month;
			car[j+1].reg_date.month=swap1;
			swap1=car[j].ns_date.day;
			car[j].ns_date.day=car[j+1].ns_date.day;
			car[j+1].ns_date.day=swap1;
			swap1=car[j].ns_date.month;
			car[j].ns_date.month=car[j+1].ns_date.month;
			car[j+1].ns_date.month=swap1;
			swap1=car[j].ns_date.year;
			car[j].ns_date.year=car[j+1].ns_date.year;
			car[j+1].ns_date.year=swap1;
			}
		}
	}
	cout<<"Sorting sucessfull!"<<endl;
}
int main(){
	int choice;
	 do{
	 	cout<<"\t"<<"*****"<<"MENU"<<"*****"<<endl
	 	      <<"1- Add a new car to directory"<<endl
			  <<"2- Delete a car from the directory"<<endl
 	          <<"3- List available cars in the directory"<<endl
		      <<"4- Search a car: "<<endl 
     		       <<"\t"<<"A - Search according to car id"<<endl
     		       <<"\t"<<"B - Search according to registration year"<<endl
	          <<"5- Update car information"<<endl
	          <<"6- Sort according to car id"<<endl
	          <<"7- Quit"<<endl;
		cout<<"Please select your choice: ";

	 	cin>>choice;
	 	
	 if(choice==1){
	 		Add();
	 		continue;
	 	}
	 	if(choice==2){
	 		deletecar();
	 		continue;
	 	}	
		if(choice==3){ 
			list();
			continue;
		}
		if(choice==4){
			search(); 
			continue;
		}
		if(choice==5){
			update();
			continue;
		}
		if(choice==6){
			bubblesort();
			continue;
		}
		if(choice==7){
			cout<<"See you!";
			continue;
		}
		
		if(choice!=7){
			cout<<"Please choose between 1-7, Thanks!"<<endl;			 	
   		}	
	 }while(choice!=7);

	return -1;
}
