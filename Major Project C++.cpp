#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

fstream gm;
fstream tm;

class gym
{
    int d,m,y,age,plan;
    char nm[30],add[40];
    char mob[10];
    int ch;

public :

	void mn()
	{
		cout << "\n\n1 for Member";
   		cout << "\n2 for Fee";
    	cout << "\n0 for exit";
    	cout << "\nEnter your choice : ";
    	cin >> ch;

    	switch(ch)
    	{
    		case 1 :
        		member();
        		break;

    		/*case 2 :
        		fee;
        		break;
			*/
    		case 0 :
        		exit(0);
        		break;

    		default :
        		cout << "Wrong choice try again";
        		break;
    	}

	}

     void member()
    {
        cout << "\n\n1 for add member";
        cout << "\n2 for show all members";
        cout << "\n3 for search member";
        cout << "\n4 for update member";
        cout << "\n5 for delete a member";
        cout << "\n0 for goto main menu";
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch(ch)
        {
        case 1 :
            addmem();
            break;

        case 2 :
            showmem();
            break;

        case 3 :
            searchmem();
            break;

        /*case 4 :
            update;
            break;*/

        case 5 :
            delmem();
            break;
            
        case 6 : 
        	num();
        	break;

        case 0 :
            mn();
            break;
        }
    }

    void addmem()
    {
    	gm.open("Gym_mem.txt",ios::binary|ios::out);
    	char chh;
    do
	{
        cout << "\n\nEnter name : ";
        cin >> nm;

        cout << "\nEnter Address : ";
        cin >> add;

        cout << "\nEnter Age : ";
        cin >> age;

        cout << "\nEnter date of joining D M Y in this format : ";
        cin >> d >> m >> y;

        cout << "\nEnter mobile no. : ";
        cin >> mob;
        
        cout << "\nEnter plan in months : ";
        cin >> plan;
        
        gm<<nm<<" "<<add<<" "<<age<<" "<<d<<"-"<<m<<"-"<<y<<" "<<mob<<" "<<plan<<endl;
        
        cout << "\nRecord saved";
        cout << "\nYou want to enter more record Y/N : ";
        cin >> chh;
    }
    while(chh == 'Y' || chh == 'y');
    	gm.close();
        member();
    }
    
	void showmem()
	{
		gm.open("gym_mem.txt",ios::in);
		while(gm)
		{
			gm>>nm>>add>>age>>d>>m>>y>>mob>>plan;
    		cout << "\n\nName : "<<nm;
    		cout << "\nAddress : "<<add;
    		cout << "\nAge : "<<age;
    		cout << "\nDate of joining : "<<d<<m<<y;
    		cout << "\nMobile no. : " <<mob;
    		cout << "\nPlan : " <<plan;
		}
		gm.close();
		member();
	}
	
	void searchmem()
	{
		char name[30];
		int f = 0;
		cout << "Enter name which you want to search : ";
		cin >> name;
		
		gm.open("gym_mem.txt",ios::binary|ios::in);
		while(!gm.eof())
		{
			gm>>nm>>add>>age>>d>>m>>y>>mob>>plan;
	    	if(strcmp(name,nm)==0)
			{
			    f = 1;
			    break;
			}
			else 
				f = 0;
		}
		
		if(f == 1)
		{
			cout << "\nName : " << nm;
			cout << "\nAddress : " << add;
			cout << "\nAge : " << age;
			cout << "\nDate of joining : " << d << m << y;
			cout << "\nMobile no. : " << mob;
			cout << "\nPlan : " << plan;
		}
		else 
			cout << "Record not found";
		gm.close();
		member();
	}
	
	void delmem()
	{
		char name[30];
		int f = 0;
		cout << "\nEnter name which you want to delete : ";
		cin >> name;
		
		gm.open("gym_mem.txt",ios::in);
		tm.open("temp.txt",ios::app|ios::out);
		
		while(gm)
		{
			gm>>nm>>add>>age>>d>>m>>y>>mob>>plan;
			if(strcmp(name,nm)!=0)
			{
				tm<<nm<<" "<<add<<" "<<age<<" "<<d<<"-"<<m<<"-"<<y<<" "<<mob<<" "<<plan<<endl;
			}
			else
				cout << "\nRecord not found";
		}
	/*	tm>>nm>>add>>age>>d>>m>>y>>mob>>plan;
		if(f == 1)
			cout << "\nRecord not found";
		else
			cout << "\nRecord deleted"; */
		gm.close();
		tm.close();
		remove("gym_mem.txt");
		rename("temp.txt","gym_mem.txt");
		member();
	}
	
	int num()
	{
		int a = strlen("gm");
		cout << a;
	}	

};

main()
{
    gym a;
    a.mn();
    
    return 0;
}
