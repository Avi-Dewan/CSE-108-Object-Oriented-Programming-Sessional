#include<iostream>

using namespace std;


class Student{
    private:
        int id;
        int level;
        int term;
        double cgpa;
        int departmentCode;

    public:
        Student(){

        }

        Student(int sId,int deptCode){
            //default will be level1 term1
            id = sId;
            level = 1;
            term = 1;
            departmentCode = deptCode;
        }
        Student(int sId,int sLevel, int sTerm,int deptCode){
            id = sId;
            level = sLevel;
            term = sTerm;
            departmentCode = deptCode;
        }

        //setter getter for all private variables
        void setID(sId) {
            id = sId;
        }

        void setLevel(sLevel) {
            level = sLevel;
        }

        void setTerm(sTerm) {
            term = sTerm;
        }

        void setCGPA(CGPA) {
            cgpa = CGPA;
        }

        void setdepartmentCode(deptCode) {
            departmentCode = deptCode;
        }

        int getID() {
            return id;
        }

        int getLevel() {
            return level;
        }

        int getTerm() {
            return term;
        }

        double getCGPA() {
            return cgpa;
        }

        int getdepartmentCode() {
            return departmentCode;
        }



};
