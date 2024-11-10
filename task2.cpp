//
// Created by user on 11/10/2024.
//
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string analysys(string str){

    ostringstream os;
    string buf ="";
    string voskl ="",vopr="";
    string symbols = ".!?";
    for(int i = 0; i<str.length(); i++){
        buf.push_back(str[i]);
        int z = symbols.find(str[i]);
        if(z!=string::npos){
            if(z==1) {
                voskl.append(buf);
            } else if(z==2){
                vopr.append(buf);
            }
            buf = "";
        }
    }
    os<<vopr<<"\n"<<voskl<<endl;
    return os.str();

}


int main(){
    std::ifstream f;
    f.open("example.txt");

    string line,res;
    while(getline(f,line)){
        res.append(line);
    }


    cout<<analysys(res);

    return 0;
}