#include <iostream>
using namespace std;
#include <vector>

class Employee{
public:
    int id;
    int importance;
    vector<int> subodinates;

    /*Employee(int id, int importance, vector<int> subodinates){
        this->id = id;
        this->importance;
        this->subodinates = subodinates;
    }

    Employee(int id, int importance){
        this->id = id;
        this->importance;
    }*/
};

int getImportance(vector<Employee*> employees, int id){
    
    int sum=0;
    for(auto emp : employees){
        if(emp->id == id){
            if(emp->subodinates.size()==0){
                //cout<< emp->importance <<endl;
                return emp->importance;
            } 

            for(auto id : emp->subodinates){
                sum+= getImportance(employees, id);
            }

            sum+= emp->importance;
            break;
        }
    }
    return sum;
}

int main(){
    vector<Employee*> employees;
    int id_target = 1;
    vector<int> a1 = {2,3};
    //Employee* e1 =new Employee(1,5, a1);
    Employee e1;
    e1.id = 1; e1.importance =5; e1.subodinates = a1;
    employees.push_back(&e1);

    Employee e2;
    e2.id = 2; e2.importance =3; 
    employees.push_back(&e2);

    Employee e3;
    e3.id = 3; e3.importance =3; 
    employees.push_back(&e3);
    

    int sum = getImportance(employees, id_target);
    cout <<sum << endl;

    
}