
#include "SIGN.h"

/*
 * iostream for keybord
 * fstream for files
 * stringstream for internal messages
*/
using namespace std;

#ifdef WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
#include "Container.h"


int main() {
    Container cont;

    system(CLEAR);
    int inp;
    do{
        cout<<"1. Print container\n";
        cout<<"2. Clear container\n";
        cout<<"3. Work with SIGN by index\n";
        cout<<"4. Add new SIGN\n";
        cout<<"5. Zodiac SIGN choose\n";
        cout<<"6. End\n";

        cin>>inp;
        system(CLEAR);

        switch(inp){
            case 1:
                cout<<"Number of elements in cont: "<<cont.length()<<"\n";
                cont.operator<<(cout);
                break;
            case 2:
                cont.clear();
                cout<<"cont has been cleared.\n";
                break;
            case 3:
                cout<<"Enter index of element: ";
                {
                    int inpd;
                    int inpda;
                    SIGN* element;
                    cin>>inpd;
                    try{
                        element = cont[inpd];
                    }catch (const out_of_range exc){
                        cout<<"Incorrect index!\n";
                        break;
                    };
                    do{
                        element->operator<<(cout);
                        cout<<"1. Change name\n";
                        cout<<"2. Change surname\n";
                        cout<<"3. Change zodiac\n";
                        cout<<"4. Change birthday\n";
                        cout<<"5. Delete\n";
                        cout<<"6. Back\n";


                        string buf;
                        int arr[3];
                        cin>>inpda;
                        system(CLEAR);

                        switch(inpda){
                            case 1:
                                cout<<"Enter new information: ";
                                cin>>buf;
                                element->setName(buf);
                                break;
                            case 2:
                                cout<<"Enter new information: ";
                                cin>>buf;
                                element->setSurname(buf);
                                break;
                            case 3:
                                cout<<"Enter new information: ";
                                cin>>buf;
                                element->setZodiac(buf);
                                break;
                            case 4:
                                cout<<"Enter new information like Day Month Year without divisors: \n";
                                cin>>arr[0]>>arr[1]>>arr[2];
                                element->setBirthday(arr);
                                break;
                            case 5:
                                cont.remove(inpd);
                                cout<<"Elenent deleted.\n";
                                inpda = 6;
                                break;
                            case 6:
                                break;
                            default:
                                cout<<"Enter existing command!\n";
                                break;
                        };
                    }while(inpda != 6);
                }
                break;
            case 4: {
                SIGN *newElement = new SIGN();
                int inpd;
                string buf1, buf2, buf3;
                int arr[3];
                cout << "Enter name: ";
                cin >> buf1;
                cout << "Enter surname: ";
                cin >> buf2;
                cout << "Enter zodiac: ";
                cin >> buf3;
                cout << "Enter birthday like Day Month Year without divisors: ";
                cin >> arr[0] >> arr[1] >> arr[2];
                newElement->setName(buf1);
                newElement->setSurname(buf2);
                newElement->setZodiac(buf3);
                newElement->setBirthday(arr);
                cont.add(newElement);
                cout << "Element added.\n";
            }
                break;
            case 5:
            {
                cout<<"enter zodiac: ";
                string buf;
                cin>>buf;
                int counter = 0;
                for(int i = 0; i<cont.length();i++){
                    if(buf == cont[i]->getZodiac()){
                        counter++;
                        cont[i]->operator<<(cout);
                    }
                }
                if(counter == 0) cout<<"There are no people with such zodiac!\n";

            }
                break;

            case 6:
                break;
            default:
                cout<<"Enter existing command!\n";
                break;
        }
    }while(inp != 6);

    return 0;
}
