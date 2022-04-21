#include "../utils/utils.h"
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        input += '\n';
        vector<int> stack;
        int ans = 0;                // 记录长路径
        int length = input.size();  
        int tab = 0;                // 计数当前栈深度
        int tmp_length = 0;         // 计数当前栈中字符个数
        int word_length = 0;        // 计数目录名或文件名的长度
        bool is_file = false;       // 当前是否是文件
        for(int i = 0; i < length; ++i){
            switch (input[i]){
            case '\n':
                // 计算长度
                stack.emplace_back(word_length);
                tmp_length += word_length;
                if (is_file){
                    int dir_length = tmp_length + stack.size() - 1;
                    ans = max(ans, dir_length);
                }
                if(i + 1 < length && input[i + 1] != '\t'){
                    tab = 0;
                    stack = {};
                    tmp_length = 0;
                }
                is_file = false;
                word_length = 0;
                break;
            case '\t':{
                int tmp_tab = 0;    // 计数最新的栈深度
                // 是否出栈
                while(input[i] == '\t'){
                    ++tmp_tab;
                    ++i;
                }
                --i; // the last is not `\t`, while it will skiped by the `++i` of loop struct
                while (tmp_tab <= tab){
                    tmp_length -= stack.back();
                    stack.pop_back();
                    --tab;
                }
                tab = tmp_tab;
                break;
            }
            case '.':
                is_file = true;
                word_length++;
                break;
            default:                
                ++word_length;
                break;
            }
        }
        return ans;
    }
};