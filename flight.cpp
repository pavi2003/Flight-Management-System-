#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Flight{
	public:
		string flightname;
		string flightnumber;
		string source;
		string destination;
		int seats;
		int seatallotment=0;
		string dept_time;
		string day;
	
		Flight(string fnum, string fname, string sour, string dest, int seat,string tm,string d) : flightnumber(fnum), flightname(fname),source(sour),destination(dest), seats(seat),dept_time(tm),day(d) {}
		
	 void displayflights() const{
	 	cout<<"Flight number:"<<flightnumber<<endl;
	 	cout<<"Flight name:"<<flightname<<endl;
	 	cout<<"Flight source:"<<source<<endl;
	 	cout<<"Flight destination:"<<destination<<endl;
	 	cout<<flightname<<" "<<"seats:"<<seats<<endl;
	 	cout<<"Departure time:"<<dept_time<<endl;
	 	cout<<"Days:"<<day<<endl;
	 }
	 void update(const string& new_source,const string& new_destination,int new_seats,const string& new_time,const string& new_day){
	 	source=new_source;
	 	destination=new_destination;
	 	seats=new_seats;
	 	dept_time=new_time;
	 	day=new_day;
	 }
	 int bookseat(){
	 	if(seats!=0){
	 		seats--;
	 		seatallotment++;
	 		return 1;
		 }
		 else
		 return 0;
	 }
	 
	 
};
class FlightManagement{
	private:
		vector<Flight>flights;
		public:
			void addflight(const Flight&flight){
				flights.push_back(flight);
			}
			void displayallflights() const{
				if(flights.empty()){
					cout<<"No flights available"<<endl;
					return;
				}
				for (const auto& flight:flights){
					flight.displayflights();
					cout<<"xxxxxxxxxxxxxxxxxxxxxxx"<<endl;
						}
				
			}
			void updateflight(const string& flightnumber){
				for( auto& flight :flights){
					if(flight.flightnumber==flightnumber){
						cout<<"Enter new source:"<<endl;
						string new_source;
						cin>>new_source;
						cout<<"Enter new destination:"<<endl;
						string new_destination;
						cin>>new_destination;
						cout<<"Enter new available seats:"<<endl;
						int new_seats;
						cin>>new_seats;
						cin.ignore();
						cout<<"Enter new time:"<<endl;
						string new_time;
						cin>>new_time;
						cout<<"Enter new days:"<<endl;
						string new_day;
						cin>>new_day;
						flight.update(new_source,new_destination,new_seats,new_time,new_day);
						cout<<"Flight details is updated"<<endl;
						cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
						return;
					}
				}
				cout<<"Flight is not found"<<endl;
				cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
			}
			void display_flightssour(const string& source, const string& destination){
				int section=1;
					cout<<"The list of flights are:"<<endl;
				for(auto& flight:flights){
					if(flight.source==source&&flight.destination==destination){
					    cout<<section<<". "<<endl;
						cout<<"Flight number:"<<flight.flightnumber<<endl;
						cout<<"Flight name:"<<flight.flightname<<endl;
						cout<<"Flight seats:"<<flight.seats<<endl;
						cout<<"Departure Time:"<<flight.dept_time<<endl;
						cout<<"Day:"<<flight.day<<endl;
						cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
						section++;
					}
				}
			}
			void bookticket(const string& source,const string& destination,const string& flightnumber){
				for(auto& flight:flights){
				
				if(flight.source==source&&flight.destination==destination&&flight.flightnumber==flightnumber){
					if(flight.bookseat()){
						cout<<"Flight is booked"<<endl;
						cout<<"Flight number is:"<<flight.flightnumber<<endl;
						cout<<"Seat number is:"<<flight.seatallotment<<endl;
					}
					else{
					
					cout<<"Seats are not available"<<endl;
				}
				return;
				}
			}
				cout<<"Flight is not found"<<endl;
			
				
			}
			
			void seatavailable(const string& flightnumber){
				for(auto& flight:flights){
					if(flight.flightnumber==flightnumber){
					 cout<<flight.seats<<endl;	
				}
				}
			}
			
};
	

int main(){
	FlightManagement fm;
	while(1){
		cout<<"Welcome to Flight Management System!"<<endl;
		cout<<"1.Display all the fights"<<endl;
		cout<<"2.Add new flight"<<endl;
		cout<<"3.Update the existing flight"<<endl;
		cout<<"4.Display the Seat availability"<<endl;
		cout<<"5.Book flight"<<endl;
		cout<<"6.Exit"<<endl;
		cout<<"Enter your choice:"<<endl;
		int query;
		cin>>query;
		cin.ignore();
		switch(query){
			case 1: {
			
			fm.displayallflights();
			break;
		}
			case 2: {
			
			cout<<"Enter flight Number:"<<endl;
			string flightnumber;
			cin>>flightnumber;
			cout<<"Enter flight Name:"<<endl;
			string flightname;
			cin>>flightname;
			cout<<"Enter flight Source:"<<endl;
			string source;
			cin>>source;
			cout<<"Enter flight destination:"<<endl;
			string destination;
		    cin>>destination;
			cout<<"Enter Seat Availability:"<<endl;
			int seats;
			cin>>seats;
			cin.ignore();
			cout<<"Enter Departure Time:"<<endl;
			string dept_time;
		    getline(cin,dept_time);
			
			cout<<"Enter day:"<<endl;
			string day;
		getline(cin,day);
		
			fm.addflight(Flight(flightnumber,flightname,source,destination,seats,dept_time,day));
			cout<<"Flight is added"<<endl;
			break;
		}
			case 3:{

				cout<<"Enter Flight number to update:"<<endl;
				string flightnumber;
				cin>>flightnumber;
				fm.updateflight(flightnumber);
				break;
			}
			case 4:{
				cout<<"Enter flight number to check seats:"<<endl;
				string flightnumber;
				cin>>flightnumber;
				fm.seatavailable(flightnumber);
				break;
			}
			case 5:{
				cout<<"Enter the source and destination to book"<<endl;
				string source,destination;
				cin>>source;
				cout<<"<->";
				cin>>destination;
				
				fm.display_flightssour(source,destination);
				cout<<"Enter Flight number:"<<endl;
				string flightnumber;
				cin>>flightnumber;
				cin.ignore();
			
				fm.bookticket(source,destination,flightnumber);
				break;
			}
			case 6:{
				cout<<"Flight Management System is exited."<<endl;
				break;
			}
			default:{
				cout<<"Invalid query.Try another queries"<<endl;
				break;
			}
			
			
			 
		}
		
	}
}