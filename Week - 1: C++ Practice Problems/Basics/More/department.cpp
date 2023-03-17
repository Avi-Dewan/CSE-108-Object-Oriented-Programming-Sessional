#include<iostream>
#include "student.cpp"

using namespace std;


class Department{
    private:
        int capacity;
        int level;
        int term;
        Student *students;
        int departmentCode;
        int noOfStudents;

    public:
        Department(){
            this.capacity = 3;
            this.noOfStudents = 0;
            students = new Student[this.capacity];
        }

        Department(int level,int term, int capacity, int deptCode){
            //allocate students array by the capacity
            this.level = level;
            this.term = term;
            this.capacity = capacity;
            this.departmentCode = deptCode;
            this.noOfStudents = 0;
            students = new Student[this.capacity];
        }

        bool addStudent(Student student){
            //add student information into the array
            students[noOfStudents] = student;
            noOfStudents++;
            return true;
        }

        bool removeStudent(int byId){
            int rmIdx = 0;
            for(int i = 0; i < noOfStudents; i++) {
               if(students[i].getID() == byId) {
                    rmIdx = i;
                    break;
               }
             }

             noOfStudents--;

             for(int i = rmIdx; i < noOfStudents; i++) {
                    students[i] = students[i+1];
             }

            return false;
        }

        Student getStudent(int byId){
            //check if that id exists
             int idx = 0;
            for(int i = 0; i < noOfStudents; i++) {
               if(students[i].getID() == byId) {
                    idx = i;
                    break;
               }
             }
            return students[idx];
        }

        ~Department() {
            delete []students;
        }


};
