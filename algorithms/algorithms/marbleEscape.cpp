#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
#include <cstring>
using namespace std;
/*
int n, m;
char map[10][10];
int v[10][10];

pair<int, int> e;
int ans=99999;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

void escape(pair<int,int> r, pair<int,int> b, int cnt) {
	int rr = r.first; int rc = r.second;
	int br = b.first; int bc = b.second;

	queue<pair<int,int>> rq; queue<pair<int,int>> bq;
	rq.push(make_pair(rr, rc));
	bq.push(make_pair(br, bc));

	v[rr][rc] = cnt;

	while (!rq.empty() && !bq.empty()) {
		int flag = 0;
		cout << rq.empty() << " " << bq.empty() << endl;
		rr = rq.front().first; rc = rq.front().second;
		br = bq.front().first; bc = bq.front().second;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << v[i][j];
			}
			cout << endl;
		}
		
		cout << bq.front().first << " " << bq.front().second << endl;

		rq.pop();
		bq.pop();
		for (int i = 0; i < 4; i++) {
			if ((rr + dr[i] >= 0 && rr + dr[i] < n && rc + dc[i] >= 0 && rc + dc[i] < m)) {
				if (map[rr + dr[i]][rc + dc[i]] == '.' || map[rr + dr[i]][rc + dc[i]] == 'R') {
					if (v[rr + dr[i]][rc + dc[i]] == -1) {
						int tmp_dr = dr[i]; int tmp_dc = dc[i];
						if (map[br + dr[i]][bc + dc[i]] == '.' || map[br + dr[i]][bc + dc[i]] == 'B') {
							while (map[br + tmp_dr][bc + tmp_dc] == '.' || map[br + tmp_dr][bc + tmp_dc] == 'B') {
								tmp_dr += dr[i]; tmp_dc += dc[i];
							}
							int tmp_br = br + tmp_dr - dr[i]; int tmp_bc = bc + tmp_dc - dc[i];

							if (map[tmp_br + dr[i]][tmp_bc + dc[i]] == 'O') {
								ans = 99999;
							}
							bq.push(make_pair(tmp_br, tmp_bc));
						}
						else {
							if (bq.empty()) bq.push(make_pair(br, bc));
						}

						tmp_dr = dr[i]; tmp_dc = dc[i];
						while (map[rr + tmp_dr][rc + tmp_dc] == '.' || map[rr + tmp_dr][rc + tmp_dc] == 'R') {
							v[rr + tmp_dr][rc + tmp_dc] = cnt + 1;
							tmp_dr += dr[i]; tmp_dc += dc[i];							
						}

						
						int tmp_rr = rr + tmp_dr - dr[i]; int tmp_rc = rc + tmp_dc - dc[i];
						
						
						if (map[tmp_rr+dr[i]][tmp_rc+dc[i]] == 'O') {
							if (ans > cnt+1) ans = cnt+1;
						}

						rq.push(make_pair(tmp_rr, tmp_rc));
						
					}
					else {
						if (bq.empty()) bq.push(make_pair(br, bc));
					}
				}
				else {
					if (map[rr + dr[i]][rc + dc[i]] == 'O') {
						if (ans > cnt + 1) 
							ans = cnt + 1;
					}

				}
			}
		}
		cnt++;
	}

}

int main() {
	memset(v, -1, sizeof(v));
	pair<int, int> r;
	pair<int, int> b;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				r.first = i; r.second = j;
			}
			if (map[i][j] == 'B') {
				b.first = i; b.second = j;
			}
			if (map[i][j] == 'O') {
				e.first = i; e.second = j;
			}
		}
	}

	escape(r, b, 0);

	
	if (ans != 99999)
		cout << ans << endl;
	else
		cout << -1 << endl;
	
	return 0;
}
*/
int dx[] = {0,0,1,-1}; 
int dy[] = {1,-1,0,0}; 
int d[10][10][10][10]; 
int hx,hy; 
pair<bool,bool> simulate(vector<string> &a, int k, int &x, int &y) {    
	if (a[x][y] == '.') return make_pair(false, false);    
	int n = a.size();   
	int m = a[0].size();    
	bool moved = false;    
	while (true) {       
		int nx = x+dx[k];       
		int ny = y+dy[k];        
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {            
			return make_pair(moved, false);        
		}        
		if (a[nx][ny] == '#') {
			return make_pair(moved, false);       
		} else if (a[nx][ny] == 'R' || a[nx][ny] == 'B') {  
			return make_pair(moved, false);       
		} else if (a[nx][ny] == '.') {         
			swap(a[nx][ny], a[x][y]);          
			x = nx;          
			y = ny;       
			moved = true;  
		} else if (a[nx][ny] == 'O') {      
			a[x][y] = '.';        
			moved = true;        
			return make_pair(moved, true);    
		}   
	}    
	return make_pair(false, false); 
} 
pair<bool,bool> next(vector<string> a, int &rx, int &ry, int &bx, int &by, int dir) { 
	a[rx][ry] = 'R';  
	a[bx][by] = 'B';  
	bool hole1=false, hole2=false;  
	while (true) {      
		auto p1 = simulate(a, dir, rx, ry);    
		auto p2 = simulate(a, dir, bx, by);   
		if (p1.first == false && p2.first == false) {   
			break;      
		}       
		if (p1.second) hole1 = true;   
		if (p2.second) hole2 = true;   
	} 
	return make_pair(hole1, hole2);
} 
int main() {  
	int n, m; 
	cin >> n >> m;  
	vector<string> a(n); 
	for (int i=0; i<n; i++) {  
		cin >> a[i];   
	}    
	int ans = -1;  
	queue<tuple<int,int,int,int>> q;   
	int rx,ry,bx,by;  
	for (int i=0; i<n; i++) { 
		for (int j=0; j<m; j++) {    
			if (a[i][j] == 'O') {  
				hx = i; hy = j;    
			} else if (a[i][j] == 'R') {
				rx = i; ry = j;            
				a[i][j] = '.';         
			} else if (a[i][j] == 'B') {      
				bx = i; by = j;            
				a[i][j] = '.';      
			}        
		}    
	}   
	memset(d,-1,sizeof(d)); 
	q.emplace(rx,ry,bx,by);
	d[rx][ry][bx][by] = 0;   
	bool found = false;   
	while (!q.empty()) {  
		tie(rx,ry,bx,by) = q.front();    
		q.pop();      
		for (int k=0; k<4; k++) { 
			bool hole1, hole2;      
			int nrx = rx, nry = ry, nbx = bx, nby = by;    
			tie(hole1,hole2) = next(a,nrx,nry,nbx,nby,k);  
			if (hole2) continue;       
			if (hole1) {              
				found = true;         
				if (d[rx][ry][bx][by] + 1 <= 10) {
					ans = d[rx][ry][bx][by] + 1;
				}
				break;         
			}          
			if (d[nrx][nry][nbx][nby] != -1) continue; 
			q.emplace(nrx,nry,nbx,nby);         
			d[nrx][nry][nbx][nby] = d[rx][ry][bx][by] + 1; 
		}       
		if (found) {    
			break;      
		}  
	}

	cout << ans << '\n';   
	return 0;
}

