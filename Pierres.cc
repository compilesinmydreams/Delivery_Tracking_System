#include "Pierres.h"

Pierres::Pierres(){

}
Pierres::~Pierres(){
	for(int i = 0; i<franchiseArr.size();i++){
		delete franchiseArr[i];
	}
	for(int j = 0;j<driverArr.size();j++){
		delete driverArr[j]; 
	}

}
void Pierres::addDriver(const string& name, Location dloc){
	Driver* d=new Driver(name, dloc);
	driverArr.push_back(d);
}
void Pierres::addFranchise(const string& name, Location floc){
	Franchise* f= new Franchise(name,floc);
	franchiseArr.push_back(f);
}

int Pierres::findClosestFranchise(Location custLocation){
	int ind=0;
	int min=franchiseArr[0]->getLocation().getDistance(custLocation);
	for(int i=0;i<franchiseArr.size();i++){
		int dis=franchiseArr[i]->getLocation().getDistance(custLocation);
		if(dis<min){
			min=dis;
			ind=i;
		}
	}
	return ind;
}
void Pierres::takeOrder(const string& customerName, int menuItem, Location custLocation){
	Order* newOrd= new Order(customerName, menuItem, custLocation);
	franchiseArr[findClosestFranchise(custLocation)]->addOrder(newOrd);
	
}

void Pierres::driverPickup(const string& franchiseId, int numOrders){
    bool flag = false;
    for(int i = 0; i < franchiseArr.size(); i++){
       if(franchiseArr[i]->equals(franchiseId)){
            flag = true;
            int min;
            int ind = -1;
            for(int j = 0; j < driverArr.size(); j++){
                if(driverArr[j]->isFree()){
                    if(ind == -1){
                        min = driverArr[j]->getLocation().getDistance(franchiseArr[i]->getLocation());
                        ind = j;
                    }
                    else{
                    	int dis = driverArr[j]->getLocation().getDistance(franchiseArr[i]->getLocation());
                        if(dis < min){
                            min = dis;
                            ind = j;
                        }
                    }
                }
            }
            driverArr[ind]->setLocation(franchiseArr[i]->getLocation());
            if(numOrders <= franchiseArr[i]->getNumOrders()){
                for(int j = 0; j < numOrders; j++){
                    driverArr[ind]->addOrder(franchiseArr[i]->getNextOrder());
                }
            }
            else{
            	numOrders = franchiseArr[i]->getNumOrders();
                for(int j = 0; j < numOrders; j++){
                    driverArr[ind]->addOrder(franchiseArr[i]->getNextOrder());
                }
            }
           
            cout<< driverArr[ind]->getName()<<" with ID "<< driverArr[ind]->getId()<< " has picked up the order(s)"<<endl;
            break;
        }
        
    }
    if(flag == false){
        cout<<"Franchise Id not found"<<endl;
    }

}




void Pierres:: driverDeliver(const string& driverId, int numOrders){
	bool flag=false;
	for(int i = 0;i<driverArr.size();i++){
		if(driverArr[i]->equals(driverId)){
			
			flag=true;
			if(numOrders<=driverArr[i]->getNumOrders()){
				
				for(int j=0;j<numOrders;j++){
					cout<<"Driver "<<driverArr[i]->getId();
					Order* temp= driverArr[i]->getNextOrder();
					cout<<" is delivering for ";
					temp->print();
					cout<<" at ";
					temp->getLocation().print();
					cout<<"";
					driverArr[i]->setLocation(temp->getLocation());
					delete temp;
				}
				
			}
			if(numOrders>driverArr[i]->getNumOrders()){
				numOrders = driverArr[i]->getNumOrders();
				for(int j=0;j<numOrders;j++){
					cout<<"Driver "<<driverArr[i]->getId();
					Order* temp= driverArr[i]->getNextOrder();
					cout<<" is delivering for ";
					temp->print();
					cout<<" at ";
					temp->getLocation().print();
					cout<<"\n ";
					driverArr[i]->setLocation(temp->getLocation());
					delete temp;
					
				}
			}
			
			break;
		}
		
	}
	if(flag==false){
		cout<<"Driver Id not found"<<endl;
	}
	

}

void Pierres::printFranchises()const{
	for(int i = 0;i<franchiseArr.size();i++){
		franchiseArr[i]->print();
	}
}

void Pierres::printDrivers()const{
	for(int i = 0; i<driverArr.size();i++){
		driverArr[i]->print();
	}
}
