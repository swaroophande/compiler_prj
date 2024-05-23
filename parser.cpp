#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

map<pair<int,string>,pair<int,int>> action = {
    {{0,"BEGIN"},{2,1}},

    {{2,"END"},{6,0}},
    {{2,"PF"},{8,1}},
    {{2,"DATATYPE"},{9,1}},
    {{2,"IDEN"},{11,1}},
    {{2,"FOR_LOOP"},{10,1}},

    {{3,"END"},{12,1}},

    {{4,"END"},{6,0}},
    {{4,"PF"},{8,1}},
    {{4,"DATATYPE"},{9,1}},
    {{4,"IDEN"},{11,1}},
    {{4,"FOR_LOOP"},{10,1}},

    {{5,"END"},{6,0}},
    {{5,"PF"},{8,1}},
    {{5,"DATATYPE"},{9,1}},
    {{5,"IDEN"},{11,1}},
    {{5,"FOR_LOOP"},{10,1}},

    {{6,"END"},{6,0}},
    {{6,"PF"},{8,1}},
    {{6,"DATATYPE"},{9,1}},
    {{6,"IDEN"},{11,1}},
    {{6,"FOR_LOOP"},{10,1}},

    {{7,"END"},{6,0}},
    {{7,"PF"},{8,1}},
    {{7,"DATATYPE"},{9,1}},
    {{7,"IDEN"},{11,1}},
    {{7,"FOR_LOOP"},{10,1}},

    {{8,"DQ"},{17,1}},

    {{9,"IDEN"},{18,1}},

    {{10,"IDEN"},{19,1}},

    {{11,"ASSIGN_OP"},{20,1}},

    {{12,"$"},{1,0}},

    {{13,"END"},{2,0}},

    {{14,"END"},{3,0}},

    {{15,"END"},{4,0}},

    {{16,"END"},{5,0}},

    {{17,"STRING"},{21,1}},

    {{18,"END"},{10,0}},
    {{18,"PF"},{10,0}},
    {{18,"DATATYPE"},{10,0}},
    {{18,"IDEN"},{10,0}},
    {{18,"COMMA"},{23,1}},
    {{18,"FOR_LOOP"},{10,0}},

    {{19,"ASSIGN_OP"},{24,1}},

    {{20,"DQ"},{28,1}},
    {{20,"NUM"},{26,1}},
    {{20,"REAL"},{27,1}},

    {{21,"DQ"},{29,1}},

    {{22,"END"},{8,0}},
    {{22,"PF"},{8,0}},
    {{22,"DATATYPE"},{8,0}},
    {{22,"IDEN"},{8,0}},
    {{22,"FOR_LOOP"},{8,0}},

    {{23,"IDEN"},{30,1}},

    {{24,"NUM"},{31,1}},

    {{25,"END"},{12,0}},
    {{25,"PF"},{12,0}},
    {{25,"DATATYPE"},{12,0}},
    {{25,"IDEN"},{12,0}},
    {{25,"FOR_LOOP"},{12,0}},

    {{26,"END"},{13,0}},
    {{26,"PF"},{13,0}},
    {{26,"DATATYPE"},{13,0}},
    {{26,"IDEN"},{13,0}},
    {{26,"FOR_LOOP"},{13,0}},

    {{27,"END"},{14,0}},
    {{27,"PF"},{14,0}},
    {{27,"DATATYPE"},{14,0}},
    {{27,"IDEN"},{14,0}},
    {{27,"FOR_LOOP"},{14,0}},

    {{28,"STRING"},{32,1}},

    {{29,"END"},{7,0}},
    {{29,"PF"},{7,0}},
    {{29,"DATATYPE"},{7,0}},
    {{29,"IDEN"},{7,0}},
    {{29,"FOR_LOOP"},{7,0}},

    {{30,"END"},{10,0}},
    {{30,"PF"},{10,0}},
    {{30,"DATATYPE"},{10,0}},
    {{30,"IDEN"},{10,0}},
    {{30,"COMMA"},{23,1}},
    {{30,"FOR_LOOP"},{10,0}},

    {{31,"TO"},{34,1}},

    {{32,"DQ"},{35,1}},

    {{33,"END"},{9,0}},
    {{33,"PF"},{9,0}},
    {{33,"DATATYPE"},{9,0}},
    {{33,"IDEN"},{9,0}},
    {{33,"FOR_LOOP"},{9,0}},

    {{34,"NUM"},{36,1}},

    {{35,"END"},{15,0}},
    {{35,"PF"},{15,0}},
    {{35,"DATATYPE"},{15,0}},
    {{35,"IDEN"},{15,0}},
    {{35,"FOR_LOOP"},{15,0}},

    {{36,"END"},{11,0}},
    {{36,"PF"},{11,0}},
    {{36,"DATATYPE"},{11,0}},
    {{36,"IDEN"},{11,0}},
    {{36,"FOR_LOOP"},{11,0}},

    {{1,"$"},{-1,-1}},
};

map<pair<int,string>,int> go_to = {
    {{0,"S"},1},

    {{2,"stmts"},3},
    {{2,"print"},4},
    {{2,"decleration"},5},
    {{2,"for_loop"},6},
    {{2,"assignment"},7},

    {{4,"stmts"},13},
    {{4,"print"},4},
    {{4,"decleration"},5},
    {{4,"for_loop"},6},
    {{4,"assignment"},7},

    {{5,"stmts"},14},
    {{5,"print"},4},
    {{5,"decleration"},5},
    {{5,"for_loop"},6},
    {{5,"assignment"},7},

    {{6,"stmts"},15},
    {{6,"print"},4},
    {{6,"decleration"},5},
    {{6,"for_loop"},6},
    {{6,"assignment"},7},

    {{7,"stmts"},16},
    {{7,"print"},4},
    {{7,"decleration"},5},
    {{7,"for_loop"},6},
    {{7,"assignment"},7},

    {{18,"dlist"},22},

    {{20,"list"},25},

    {{30,"dlist"},33},
};

unordered_map<int,int> no_of_grammar_sym = {
    {0,1},
    {1,3},
    {2,2},
    {3,2},
    {4,2},
    {5,2},
    {6,0},
    {7,4},
    {8,3},
    {9,3},
    {10,0},
    {11,6},
    {12,3},
    {13,1},
    {14,1},
    {15,3}
};

unordered_map<int,string> g_sym = {
    {0,"S'"},
    {1,"S"},
    {2,"stmts"},
    {3,"stmts"},
    {4,"stmts"},
    {5,"stmts"},
    {6,"stmts"},
    {7,"print"},
    {8,"decleration"},
    {9,"dlist"},
    {10,"dlist"},
    {11,"for_loop"},
    {12,"assignment"},
    {13,"list"},
    {14,"list"},
    {15,"list"}
};

vector<string> splitString(const string& input) {
    vector<string> words;
    istringstream iss(input);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

unordered_map<int,string> grammar = {
    {0,"S' -> S"},
    {1,"S -> BEGIN stmts END"},
    {2,"stmts -> print stmts"},
    {3,"stmts -> decleration stmts"},
    {4,"stmts -> for_loop stmts"},
    {5,"stmts -> assignment stmts"},
    {6,"stmts -> ''"},
    {7,"print -> PF DQ STRING DQ"},
    {8,"decleration -> DATATYPE IDEN dlist"},
    {9,"dlist -> COMMA IDEN dlist"},
    {10,"dlist -> ''"},
    {11,"for_loop -> FOR_LOOP IDEN ASSIGN_OP NUM TO NUM"},
    {12,"assignment -> IDEN ASSIGN_OP list"},
    {13,"list -> NUM"},
    {14,"list -> REAL"},
    {15,"list -> DQ STRING DQ"}
};

void changeColor(int desiredColor){ 
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor); 
}

int main(){
    ifstream t("tokens.txt");
    stringstream buffer;
    buffer << t.rdbuf();
    string s = buffer.str();
    vector<string> input;
    input = splitString(s);
    input.push_back("$");
    vector<int> st;
    st.push_back(0);
    int i=0;
    cout << left << setw(80) << "STACK" << left << setw(20) << "INPUT";
    cout << "ACTION" << endl;
    while(1){
        if (st.size()<1){
            changeColor(5);
            cout << "Error" << endl;
            changeColor(7);
            break;
        }
        string a = input[i];
        int s = st.back();
        string ss = "";
        for (auto j: st) ss += to_string(j)+"|";
        ss.pop_back();
        cout << left << setw(80) << ss ;
        cout << left << setw(20) << a;
        if (action[{s,a}].second==-1){
            changeColor(2);
            cout << "Accepted" << endl;
            changeColor(7);
            break;
        }
        else if (action[{s,a}]!=make_pair(0,0)) {
            if (action[{s,a}].second==1){
                st.push_back(action[{s,a}].first);
                cout<< "Shift " << a << endl;
                i++;
            }else{
                int no = no_of_grammar_sym[action[{s,a}].first];
                while(no--) st.pop_back();
                st.push_back(go_to[{st.back(),g_sym[action[{s,a}].first]}]);
                cout << "Reduce " <<  g_sym[action[{s,a}].first] <<   " : "  << grammar[action[{s,a}].first] << endl;
            }
        }
        else {
            changeColor(4);
            cout << "Error" << endl;
            changeColor(7);
            break;
        }
    }
     
    return 0;
}

