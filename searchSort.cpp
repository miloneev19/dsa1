#include<iostream>
using namespace std;
#define MAX 5
struct Student_info {
public:
    int roll_no;
    string name;
    double sgpa;

    Student_info(int roll, string name, double sgpa){
        this->roll_no = roll;
        this->name = name;
        this->sgpa = sgpa;

    }
    Student_info(){
        this->roll_no = 0;
        this->name = "";
        this->sgpa = 0;
    }
};
class Student_Database {
public:
    struct Student_info students[MAX];   //creating array of structures of size 5 i.e. to store info of 5 students
    bool initialized = false;

    void getdata() {
        struct Student_info s1;
        for (int i = 0; i < 5; i++) {
            cout << "Enter name of Student" << endl;
            cin >> s1.name;
            cout << "Enter Roll No" << endl;
            cin >> s1.roll_no;
            cout << "Enter SGPA" << endl;
            cin >> s1.sgpa;
            int j=0;
            while(j<5)
            {
                students[i]={s1.roll_no,s1.name,s1.sgpa};
                j++;
            }

        }
        initialized = true;
    }
    void BubbleSort()
    {
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<4-i;j++)
            {
                if(students[j].roll_no>students[j+1].roll_no)
                {
                    //swap them
                    Student_info temp=students[j];
                    students[j]=students[j+1];
                    students[j+1]=temp;
                }
            }
        }
    }
    void display()
    {
        if(initialized) {
            cout << "Student details are shows as below" << endl;
            cout << "Roll Number" << "\t\t\tName" << "\t\t\t\tSGPA" << endl;
            int i = 0;
            while (i < 5) {
                cout << students[i].roll_no << "\t\t\t\t" << students[i].name << "\t\t\t\t" << students[i].sgpa << endl;
                i++;
            }
        }
        else{
            cout<<"No records to display!"<<endl;
        }
    }

    void SearchUsingSGPA(double key_sgpa)  //linear Search
    {
        cout<<"Roll Number"<<"\t\t\tName"<<"\t\t\t\tSGPA"<<endl;
        for(int i=0;i<5;i++)
        {
            if(students[i].sgpa==key_sgpa)
            {
                cout<<students[i].roll_no<<"\t\t\t\t"<<students[i].name<<"\t\t\t\t"<<students[i].sgpa<<endl;
            }
        }
    }

    void SearchUsingName(string search_name) //binary search
    {
        //cout<<"Roll Number"<<"\t\t\tName"<<"\t\t\t\tSGPA"<<endl;
        int l=0;
        int h=MAX-1;
        while(l<h)
        {
            int mid=(l+h)/2;
            if(students[mid].name==search_name)
            {
                cout<<"Name found at "<<mid<<endl;
                cout<<students[mid].roll_no<<"\t\t\t\t"<<students[mid].name<<"\t\t\t\t"<<students[mid].sgpa<<endl;
                return;
            }
            else if(search_name>students[mid].name)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
    }

    int partition(int low, int high)
    {
        int pivot = students[high].sgpa; // pivot
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            // If current element is smaller than the pivot
            if (students[j].sgpa < pivot) {
                i++; // increment index of smaller element
                swap(students[i], students[j]);
            }
        }
        swap(students[i + 1], students[high]);
        return (i + 1);
    }

    void quickSort(int low, int high)
    {
        if (low < high) {
            /* pi is partitioning index, arr[p] is now
            at right place */
            int pi = partition(low, high);

            // Separately sort elements before
            // partition and after partition
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }


    void firstThreeTopper()
    {
        int l=0,r=5;
        quickSort(l,r);
        //printing only first three out of all
        cout<<"First Three Toppers are "<<endl;
        cout<<endl;
        cout<<"Roll Number"<<"\t\t\tName"<<"\t\t\t\tSGPA"<<endl;
        for(int i=5;i>2;i--)
        {
            cout<<students[i].roll_no<<"\t\t\t\t"<<students[i].name<<"\t\t\t\t"<<students[i].sgpa<<endl;
        }



    }

    void alphaArrangememt()  //using insertion sort
    {
        int i,j;
        for( i=1;i<5;i++)
        {
            j=i-1;
            while(j>=0 && students[j].name>students[j+1].name)
            {
                string temp= students[j].name;
                students[j].name=students[j+1].name;
                students[j+1].name=temp;
                j--; //to compare with previously sorted names
            }
        }
    }

};



int main() {
    Student_Database s;
    int choice;
    do{
        cout<<"1.Enter Student info"<<endl;
        cout<<"2.Display Student Info"<<endl;
        cout<<"3.Search Student using Sgpa"<<endl;
        cout<<"4.Enter name you want to search for"<<endl;
        cout<<"5.Display Names In alphabetical Order"<<endl;
        cout<<"6.Display first three toppers "<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"-----------------------------------------------------------------------------------------"<<endl;
        cout<<"Enter choice";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                s.getdata();
                s.BubbleSort();
                cout<<"Data Entered Successfully"<<endl;
                cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 2:
            {
                s.display();
                cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 3:
            {
                double key_sgpa;
                cout<<"Enter Sgpa you want to search for";
                cin>>key_sgpa;
                s.SearchUsingSGPA(key_sgpa);
                cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 4:
            {
                cout<<"Enter name you want to search";
                string search_name;
                cin>>search_name;
                s.SearchUsingName(search_name);
                cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 5:
            {
                s.alphaArrangememt();
                s.display();
                cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 6:
            {
                s.firstThreeTopper();
                cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
                break;
            }
            case 7:
            {
                cout<<"Thankyou for using "<<endl;
            }
        }
    }while(choice!=7);
    return 0;
}

