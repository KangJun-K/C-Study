#include<iostream>
#include<deque>
#include<string>
#include<cctype>
#include<vector>
#include<sstream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n;;
    string str;
    cin >> T;
    while(T--)
    {
        deque<int>dq;
        cin >> str >> n;
        string tmp;
        cin >> tmp;
        for(char &c : tmp)
        {
            if(c == '[' || c == ']')
            {
                c = ' ';
            }
        }
        stringstream ss(tmp);
        int num;
        char comma;

        while(ss >> num)
        {
            dq.push_back(num);
            ss >> comma;
        }
        bool is_error = false;
        bool judge = false;
        for(char cmd : str) // 범위 기반 for문이 더 깔끔하네.
        {
            if(cmd == 'R')
            {
                judge = !judge;
            }
            else if(cmd == 'D')
            {
                if(dq.empty()) { // 먼저 비어있는지 확인
                    is_error = true;
                    break; // 에러 발생! 즉시 루프 탈출
                }
                
                if(judge == false){
                    dq.pop_front();
                }
                else{
                    dq.pop_back();
                }
            }
        }

        // 최종 결과 출력은 루프가 모두 끝난 뒤 한 번만!
        if(is_error) {
            cout << "error\n";
        }
        else {
            cout << "[";
            if(judge == false) { // 정방향 출력
                for(int i = 0; i < dq.size(); i++) {
                    cout << dq[i];
                    if(i != dq.size() - 1) cout << ",";
                }
            }
            else { // 역방향 출력
                for(int i = dq.size() - 1; i >= 0; i--) {
                    cout << dq[i];
                    if(i != 0) cout << ",";
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}