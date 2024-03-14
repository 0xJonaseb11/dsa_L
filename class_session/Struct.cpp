/*
#include<iostream>


struct Node {
    int data;
    Node() {

    }
    Node(int d) {
        data = d
    }
}


int main() {
    struct Node n1(10);
    Node * n2 = new Node(20);
}

*/




#include<iostream>
using namespace std;
struct Student{
     string name;
     int age;
     string school;
     Student(){

	 }
	 Student(string n, int a, string s){
	 	name = n;
	 	age = a;
	 	school = s;
	 }
};
int main(){
	struct Student st("JONAS", 18, "RCA");
	cout<<st.name<<" is "<<st.age<<" years old and studies at "<<st.school<<endl;
	Student st2;
	st2.age = 39;
	st2.name = "SEBERA";
	st2.school = "MIT";
	cout<<st2.name<<" is "<<st2.age<<" years old and studies at "<<st2.school<<endl;
	Student *st3 = new Student("Mary", 23, "ASU");
	cout<<(*st3).name<<" is "<<(*st3).age<<" years old and studies at "<<(*st3).school<<endl;
	Student st4 = Student("BIG-DAWG", 16, "ESCM");
	cout<<st4.name<<" is "<<st4.age<<" years old and studies at "<<st4.school<<endl;

	return 0;

}
