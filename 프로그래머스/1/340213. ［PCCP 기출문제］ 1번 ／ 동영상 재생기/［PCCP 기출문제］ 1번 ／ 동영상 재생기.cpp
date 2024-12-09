#include <string>
#include <vector>

using namespace std;

int to_sec(string s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 5));
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int video_len_sec = to_sec(video_len);
    int pos_sec = to_sec(pos);
    int op_s_sec = to_sec(op_start);
    int op_e_sec = to_sec(op_end);
    
    for (int i = 0; ; ++i) {
        if (op_s_sec <= pos_sec && pos_sec <= op_e_sec) {
            pos_sec = op_e_sec;
        }
        
        if (i >= commands.size()) break;
        
        if (commands[i].compare("prev") == 0) {
            pos_sec = max(0, pos_sec - 10);
        }
        else if (commands[i].compare("next") == 0) {
            pos_sec = min(video_len_sec, pos_sec + 10);
        }
    }
    
    char ans[6] = { 0, };
    char* p = ans;
    
    *p++ = pos_sec / 60 / 10 + '0';
    *p++ = pos_sec / 60 % 10 + '0';
    *p++ = ':';
    *p++ = pos_sec % 60 / 10 + '0';
    *p++ = pos_sec % 60 % 10 + '0';
    *p = '\0';
    
    return string(ans);
}