#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Employee{
public:
    int id;
    int importance;
    vector<int> subodinates;
};

class Solution{
public:
unordered_map<int, Employee*> m;
int getImportance(vector<Employee*> employees, int id){
    for(Employee* e:employees){
        m[e->id] = e;
    }

    return dfs(id);
}

int dfs(int id){
    int result = m[id]->importance;
    for(auto sub:m[id]->subodinates){
        result+= dfs(sub);
    }

    return result;
}
};

int main(){
     vector<Employee*> employees;
    int id_target = 5;
    vector<int> a1 = {5};
 
    Employee e1;
    e1.id = 1; e1.importance =2; e1.subodinates = a1;
    employees.push_back(&e1);

    Employee e2;
    e2.id = 5; e2.importance =-3; 
    employees.push_back(&e2);

   /* Employee e3;
    e3.id = 3; e3.importance =3; 
    employees.push_back(&e3);*/
    
    Solution s;
    int sum = s.getImportance(employees, id_target);
    cout <<sum << endl;
}