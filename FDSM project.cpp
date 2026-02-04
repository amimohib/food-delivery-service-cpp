#include<iostream>
#include<string>
#include<vector>
using namespace std;

class User{
	protected:
		string name,number,address;
	public:
		void Welcome_message() {
    		cout<<"=============================================\n";
    		cout<<"   Welcome to Food Delivery Service System   \n";
    		cout<<"=============================================\n";
    		cout<<"These services are only available in: ";
    		cout<<"Defence Phase 1, Lahore\n\n";
		}	
		void user_info(){
			
			cout<<"Enter your Full name: ";
			while(true){
				getline(cin,name);
				if(name.length()>=1){			
					break;
				}
			cout<<"Please, Enter your Full name: ";
			}
			
			cout<<"Enter your phone number: ";
			while(true){
				cin>>number;
				if(number.length()==11){	
					cin.ignore();
					break;
				}
				cout<<"Please, Enter correct number: ";
			}		
	
			cout<<"Enter your home address: ";
			while(true){
				getline(cin,address);
				if(address.length()>=5){
					break;
				}
			cout<<"Please, Enter correct home address: ";
			}			
		}
		
		void user_data(){
			cout<<name<<" you will recive your order at ("<<address<<") in between 40 to 60 minutes.\n";	
			cout<<"Thank you for choosing our service.\n";
			cout<<"Please, come again.\n";
		}
		~User(){
		}		
	};
	
	
class Restaurant;
class Cart{
	protected:		
		vector <string> items;
		vector <string> item_size;
		vector <int> items_price2;
		int total=0;
	public:
		
		void check_out(){	
			cout<<"\nSr. 				Item Name 				Size 				price\n";
			for(int i=0;i<items.size();i++){
				cout<<i+1<<". 				"<<items.at(i)<<" 				"<<item_size.at(i)<<" 				"<<items_price2.at(i)<<endl;
			}			
			cout<<"\nTotal Bill: "<<total<<endl;
		}
		friend Restaurant;
		~Cart(){
		}	
	};


class Restaurant{	
	public:
	Restaurant(){
	}
	
	int option2,option3,option4;
	virtual void show_menu(Cart &c)=0;
	void menu_temp(Cart &c, string restaurant_name, string item_name, string item1, string item2, string item3, int price, string items_size1, string items_size2, string items_size3);
	virtual ~Restaurant(){
	}
};

class Fast_Food : public Restaurant{
	public:
		void show_menu(Cart &c){//def
			cout<<"You have chosen Fast Food\n\n";
			cout<<"1. Cheezious\n"
				<<"2. MEG\n"
				<<"3. Johnny and Jugnu \n";	
		
			cout<<"\nChoose any Fast Food resturant: ";	
			cin>>option2;
			cout<<endl;		
			if(option2==1){
				menu_temp(c, "Cheezious", "Pizza","Crown crust", "Tikka", "Supreme", 1500, "Regular(9)", "large(12)", "Party(14)" );
			}					
			else if(option2==2){
				menu_temp(c, "MEG", "Burger", "Chicken", "Grill", "Beef", 700, "small", "medium", "large" );		
			}
			else if(option2==3){
				menu_temp(c, "Johnny and Jugnu", "Burger", "Grill", "Wehshi", "Tortila", 800, "small", "medium", "large" );
			}				
			else{
				cout<<"Invalid input\n";
				cin>>option2;
			}
		}	
		~Fast_Food(){
		}	
	};
	
class Desi_Food : public Restaurant{
	public:
		void show_menu(Cart &c){
			cout<<"You have chosen Desi Food\n\n";
			cout<<"1. Khan Shinwari\n"
				<<"2. Ilyas Dumba Karahi\n"
				<<"3. Al-Nakhal  \n";
			
			cout<<"\nChoose any Desi Food resturant: ";	
			cin>>option2;
			cout<<endl;
		
			if(option2==1){
				menu_temp(c,  "Khan Shinwari", "Karahi","Chicken", "Beef", "Mutton", 1100, "1/2 kg", "1 kg", "2 kg" );
			}					
			else if(option2==2){
				menu_temp(c,  "Ilyas Dumba Karahi", "Karahi", "Chicken", "Beef", "Mutton", 1000, "1/2 kg", "1 kg", "2 kg"  );		
			}	
			else if(option2==3){
				menu_temp(c,  "Al-Nakhal", "Karahi", "Chicken", "Beef", "Mutton", 1200, "1/2 kg", "1 kg", "2 kg" );
			}
			else{
				cout<<"Invalid input\n";
				cin>>option2;
			}			
		}
		~Desi_Food(){
		}		
	};
	
class Street_Food : public Restaurant{
	public:
		void show_menu(Cart &c){
			cout<<"You have chosen Food corner\n\n";
			cout<<"1. Queata Chai and Paratha\n"
				<<"2. Ahmad Burger\n"
				<<"3. BBR Shawarma King\n";
		
			cout<<"\nChoose any Food street corner: ";
			cin>>option2;
			cout<<endl;
					
			if(option2==1){
				menu_temp(c,  "Queata Chai and Paratha", "Food Items","Tea", "Paratha", "Egg", 100, "1/2 kg", "1 kg", "2 kg" );
			}					
			else if(option2==2){
				menu_temp(c,  "Ahmad Burger", "Food Items", "Fries", "Burger", "Shawarma", 300, "small", "medium", "large"  );
			}
			else if(option2==3){
				menu_temp(c,  "BBR Shawarma King", "Food Items", "Chicken", "Beef", "Grill", 800, "small", "medium", "large" );
			}
			else{
				cout<<"Invalid input\n";
				cin>>option2;
			}		
		}
		~Street_Food(){
		}		
	};
	
class Dessert : public Restaurant{
	public:
		void show_menu(Cart &c){
			cout<<"You have chosen Dessert store\n\n";
			cout<<"1. Layers\n"
				<<"2. Alatto\n"
				<<"3. Crumble\n";
			
			cout<<"\nChoose any Dessert store: ";
			cin>>option2;
			cout<<endl;
				
			if(option2==1){
				menu_temp(c,  "Layers", "Desserts","Brownie", "Cup Cake", "Cold Coffee", 500, "small", "medium", "large" );
			}					
			else if(option2==2){
				menu_temp(c,  "Alatto", "Desserts", "Ice cream", "Hot Coffee", "Cold Coffee", 400, "small", "medium", "large"  );
			}
			else if(option2==3){
				menu_temp(c,  "Crumble", "Desserts", "Chocolate Chip", "Chocolate dip", "Double Chocolate", 300, "small", "medium", "large" );
			}
			else{
				cout<<"Invalid input\n";
				cin>>option2;
			}
		}
		~Dessert(){
		}
	};

void Restaurant:: menu_temp(Cart &c, string restaurant_name, string item_name,string item1, string item2, string item3, int price, string items_size1, string items_size2, string items_size3){
    
	int option3,option4;
	string items_list[3]={item1, item2, item3 };
	string items_size[3]={items_size1,items_size2, items_size3 };
	int items_price[3];
	
	cout<<"You have chossen "<<restaurant_name<<endl;
	cout<<"\nSr. 				"<<item_name<<" 			  Starting Price\n";
	for(int i=0,rem=0;i<3;i++,rem+=400){
		items_price[i]=price+rem;
		cout<<i+1<<". 				"<<items_list[i]<<" 			   "<<items_price[i]<<endl;
	}
	
	while(true){
		cout<<"\nChoose any "<<item_name <<": ";
		cin>>option3;
		if(option3 >=1 && option3<=3){
			cout<<"You have chosen "<<items_list[option3-1]<<endl<<endl;	
			break;
		}
		cout<<"\nInvalid option chosen\n";
	}
				
	int items_size_price[3];
	
	cout<<"\nSr. 				Size(in) 				Price(Rs.)\n";
	for(int i=0,rem=0;i<3;i++,rem+=200){
		items_size_price[i]=items_price[option3-1]+rem;
		cout<<i+1<<". 				"<<items_size[i]<<" 				"<<items_size_price[i]<<endl;					
	}
	
	while(true){
		cout<<"\nEnter size of "<<item_name <<": ";
		cin>>option4;
		if(option4>=1 && option4<=3){
			cout<<"You have chosen "<<items_list[option3-1]<<", size "<<items_size[option4-1]<<endl;
			c.item_size.push_back(items_size[option4-1]);
			c.items.push_back(items_list[option3-1]);
			c.items_price2.push_back(items_size_price[option4-1]);		
			c.total+=items_size_price[option4-1];
			break;
		}
		cout<<"\nInvalid option chosen\n";
		}
	}
	
int main(){
	int option1;
	char option5;
	
	User u;
	u.Welcome_message();	
	Restaurant *r=NULL;	
	u.user_info();
	Cart v;
	while(true){		
		cout<<"\nWhat would you like to order\n\n";	
		cout<<"1. Fast Food\n"
			<<"2. Desi Food\n" 
			<<"3. Street Food\n"
			<<"4. Dessert \n";
		cout<<"\nChoose any option: ";
		while(true){	
			cin>>option1;
			if(option1 >= 1 && option1 <= 4){
				if (r != NULL) {
					delete r;
					r=NULL;	
				}
				if(option1==1){
					r=new Fast_Food();
				}
				else if(option1==2){
					r=new Desi_Food();
				}
				else if(option1==3){
					r=new Street_Food();
				}
				else if(option1==4){
					r=new Dessert();
				}
				else{
					cout<<"Invalid option chossen.\n";
							
				}			
				r->show_menu( v);	
				break;
			}
			else{
				cout<<"Invalid option chossen.\n";
				cout<<"Choose again: ";
				cin>>option5;					
			}			
		}
				
		cout<<"\nAdd to cart (Y) or Check Out (N)\n";
		cout<<"Choose any option: ";
		cin>>option5;
		
		while(true){
			if(option5=='Y' || option5=='y'){
				break;
			}
			else if(option5=='N' || option5=='n'){
				v.check_out();
				u.user_data();
				return 0;				
			}
			else{
				cout<<"Invalid option chossen.\n";
				cout<<"Add to cart (Y) or Check Out (N)\n";
				cout<<"Choose again: ";
				cin>>option5;			
			}
		}		
	}
}


