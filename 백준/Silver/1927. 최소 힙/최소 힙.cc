#include "iostream"
#include "queue"

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    priority_queue<int, vector<int>, greater<int>> pq; //최소 힙 구현(오름차순 정렬)

    cin >> n;
    while(n--){
        cin >> x;

        if(x){ //x가 자연수인 경우
            pq.push(x);
            continue;
        }

        //x가 0인 경우
        if(!pq.empty()){
            cout<<pq.top()<<'\n';
            pq.pop();
        }
        else{
            cout << "0"<<'\n';
        }


    }
    return 0;

}