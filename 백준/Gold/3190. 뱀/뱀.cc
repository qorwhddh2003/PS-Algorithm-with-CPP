#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
const int APPLE = 3;
deque<pair<int, int>> snake;
int N, K, L, a, b, idx, t, x, y, ret;
int dummy_map[MAX][MAX];
int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
char dir;

bool rangeCheck(int y, int x){
    return (y < 0 || x < 0 || y >= N || x >= N);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        cin >> a >> b;
        dummy_map[a - 1][b - 1] = APPLE;
    }
    cin >> L;
    dummy_map[0][0] = 1;
    snake.push_back({0, 0});
    while(L >= 0){
        cin >> t >> dir;
        while(true){
            if(L > 0 && ret >= t) break;
            ret++;
            tie(y, x) = snake.front();
            int ny = y + dy[idx], nx = x + dx[idx];
            
            if(rangeCheck(ny, nx) || dummy_map[ny][nx] == 1){
                cout << ret;
                return 0;
            }
            
            snake.push_front({ny, nx});
            if(dummy_map[ny][nx] == APPLE){
                dummy_map[ny][nx] = 1;
            }else{
                dummy_map[ny][nx] = 1;
                dummy_map[snake.back().first][snake.back().second] = 0;
                snake.pop_back();
            }
        }
        
        if(dir == 'D'){
            idx = (idx + 1) % 4;
        }else{
            idx--;
            if(idx < 0) idx = 3;
        }
        
        L--;
    }
    
    return 0;
}
