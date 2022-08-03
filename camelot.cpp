#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <cassert>
#include <stack>

using namespace std;

#define MP make_pair
#define pb push_back
#define X first
#define Y second
#define rep(i, n) for(i = 0; i < n; i++)
#define clr(a) memset(a,0,sizeof(a))
#define cpy(d, s) memcpy(d, s, sizeof(s))
#define DEPTH 3
#define S 29999

typedef pair< int,int > ii;
 
int colour;
char orignal_board[16][14], board[S][16][14];
char pices[] = {'S', 'H'};
int value[] =  { 30,  90};
vector<vector<ii> > moves[S][2];                            //0 for non capturing moves, 1 for capturing moves
int dir[16][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1},  {-1, -1}, {-1, 1}, {1, 1}, {1, -1}, {-2, -1}, {-2, 1}, {2, 1}, {2, -1}, {-1, -2}, {-1, 2}, {1, 2}, {1, -2}};

int par[S], ans[S][2], depth[S],  m_type[S];

int random(int l, int r)
{    
    return (rand() %(r - l) + l);
}

void flipBoard(char ini[16][14], char fin[16][14])
{
    int i, ii, j, jj;
    for(i = 0, ii = 15; i < 16; i++, ii--)
            for(j = 0, jj = 11; j < 12; j++, jj--)
            {
                fin[ii][jj] = ini[i][j];
                if(ini[i][j] >= 'a' && ini[i][j] <= 'z')
                    fin[ii][jj] -= 32;
                else if(ini[i][j] >= 'A' && ini[i][j] <= 'Z')
                    fin[ii][jj] += 32;
            }
}

int input()
{
    int n, i, j;
    scanf("%d", &colour);
    rep(i, 16)
        scanf("%s", orignal_board[i]);
    if(colour == 2)
    {
        flipBoard(orignal_board, board[0]);        
    }
    else
    {
        rep(i, 16)
        rep(j, 12)
        {
            board[0][i][j] =  orignal_board[i][j];
        }
    }
    return n;
}


bool isSafe(int x, int y)
{
    if(x >= 0 && x < 16 && y >= 0 && y < 12 && orignal_board[x][y] != 'x' && !(x == 15 && (y == 6 || y == 5))) 
            return true;
    return false;
}



int isCapture(int board_no, int x, int y)    // 1 = capture, -1 = invalid move, 0 = not capure 
{
    if(board[board_no][x][y] >= 'a' && board[board_no][x][y] <= 'z')
        return 1;
    if(board[board_no][x][y] >= 'A' && board[board_no][x][y] <= 'Z')
        return -1;
    return 0;    
}




void printMove(int board_no, int type, int pos)
{
    //cout<<x1<<y1<<x2<<y2<<endl;
    for(int i = 0; i < moves[board_no][type][pos].size(); i++)
    {
        int x1 = moves[board_no][type][pos][i].X, y1 = moves[board_no][type][pos][i].Y;
        if(colour == 2)
        {
          y1 = 11 - y1;
        }
        else
        {
            x1 = 15 - x1;
        }
        putchar(y1 + 'A');
    printf("%d ", x1 + 1);
    }
    putchar('\n');
}




void plain(int board_no, int x, int y)
{
    //cout<<x<<" "<<y<<" "<<moves[board_no][0].size()<<endl;
    
        if(x == 0)
        return;
   int i, nx, ny;
    rep(i, 8)
    {
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        if(isSafe(nx, ny) && isCapture(board_no, nx, ny) == 0)
        {
            //cout<<"here"<<endl;
            vector<ii> v;
            v.pb(MP(x, y));
            v.pb(MP(nx, ny));
            moves[board_no][0].pb(v);
        }
    }
}

ii leap(int board_no, int x, int y, int d)
{
    int nx = x, ny = y;
    int ctr = 0;
    while(1)
    {
        nx += dir[d][0];
        ny += dir[d][1];
        if(isSafe(nx, ny) && isCapture(board_no, nx, ny) == -1 && ctr == 0)
               ctr++;
        else
        {
            if(isSafe(nx, ny) &&ctr == 1 && isCapture(board_no, nx, ny) == 0)
                {
                   return MP(nx, ny);
                }
            else
                return MP(x, y);
        }
    }
}

vector<ii> tmove;
vector<ii>::iterator itmove;
int vis[16][16];
int leapall(int board_no, int x, int y, int p)
{
    if(x == 0)
        return 0;
    int iii, jj;
    vis[x][y] = 1;
    if(p > 1)
    {
                        //cout<<moves[board_no][0].size()<<" "<<"here"<<endl;
                           // itmove = tmove.begin();
                    moves[board_no][0].pb(tmove);
                  //  printMove(board_no, 0, moves[board_no][0].size() - 1);
    }
    for(int i = 0; i < 8; i++)
    {
        ii t = leap(board_no, x, y, i);
        if(vis[t.X][t.Y])
        {
           //ans = 0;
        }
        else
        {
    /*    if((x == 9) && y == 5)
    rep(iii, 16)
    {
        rep(jj, 12)
        
        cout<<board[board_no][iii][jj];
        cout<<"Q"<<endl;
    }
        */
        
            tmove.pb(t);
            leapall(board_no, t.X, t.Y, p + 1);
                tmove.erase(tmove.begin() + tmove.size()-1);
        }
    }
    return 1;
}
 


void leaping(int board_no, int x, int y)
{
    int px = x, py = y;
    clr(vis);
    
    char c = board[board_no][x][y];
    board[board_no][x][y] = '-';
    tmove.clear();
    tmove.pb(MP(x, y));                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    leapall(board_no, x, y, 1);
    board[board_no][x][y] = c;
}




ii canter(char board[16][14], int x, int y, int d)
{
    int nx = x, ny = y;
    int ctr = 0;
    while(1)
    {
        nx += dir[d][0];
        ny += dir[d][1];
        if(isSafe(nx, ny) && board[nx][ny] >= 'a' && board[nx][ny] <= 'z' && ctr == 0)
               ctr++;
        else
        {
            if(ctr == 1 && board[nx][ny] == '-')
                {
                   return MP(nx, ny);
                }
            else
                return MP(x, y);
        }
    }
}

int canterall(char board[16][14], int board_no, int x, int y, int p)
{
    if(x == 0)
        return 0;
    int i, j,iii, jj;
    /*cout<<x<<" "<<y<<" "<<p<<endl;
    if(x == 12 || p > 2)
    rep(i, 16)
    {
        rep(j, 12)
        cout<<board[i][j];
        cout<<board_no<<endl;
    }
    */
    
    //vis[x][y] = 1;
   int ans = 0;
   /* if(p > 1)
    {
                        //cout<<moves[board_no][0].size()<<" "<<"here"<<endl;
                           // itmove = tmove.begin();
                    moves[board_no][1].pb(tmove);
                  //  printMove(board_no, 0, moves[board_no][0].size() - 1);
    }
    */
   for(i = 0; i < 8; i++)
    {
        ii t = canter(board, x, y, i);
        ///cout<<x<<" "<<y<<" "<<t.X<<" "<<t.Y<<endl;
        if(t.X == x && t.Y == y)
        {
            ;
        }
        else
        {
            ans = 1;
             char tboard[16][14];
            
            cpy(tboard, board);
            rep(iii, 16)
            rep(jj, 12)
            tboard[iii][jj] = board[iii][jj];
            /* if((x == 9 || x == 7) && y == 6)
    rep(iii, 16)
    {
        rep(jj, 12)
        
        cout<<tboard[iii][jj];
        cout<<"Q"<<endl;
    }
    */
        int ux = (t.X > x)?1:((t.X < x)?-1:0);
        int uy = (t.Y > y)?1:((t.Y < y)?-1:0);
        for(iii = x,  jj = y; iii <= max(x, t.X) && jj <= max(t.Y, y) && iii >= min(x, t.X) && jj >= min(t.Y, y);iii += ux, jj += uy)
        {
            tboard[iii][jj] = '-';
        }
           tmove.pb(t);
          if(canterall(tboard, board_no,t.X, t.Y, p + 1) == 0 && p >= 1)
               moves[board_no][1].pb(tmove);
           tmove.erase(tmove.begin() + tmove.size()-1);
        }
    }
    return ans;
}
 


void cantering(int board_no)
{
    int x = tmove[tmove.size() - 1].X, y =  tmove[tmove.size() - 1].Y;
    //clr(vis);
    
    char c = board[board_no][tmove[0].X][tmove[0].Y];
    board[board_no][tmove[0].X][tmove[0].Y] = '-';
    //cout<<c<<endl;
    int px = tmove[0].X, py = tmove[0].Y;
    //tmove.clear();
    
    //tmove.pb(MP(x, y));                            
    canterall(board[board_no], board_no, x, y, 1);
    assert(tmove.size()!=0);
    assert(tmove[0].X == px && tmove[0].Y == py); 
    board[board_no][tmove[0].X][tmove[0].Y] = c;
    

}


int move(int board_no)
{
    int i, j, type = 0;            //type = 0 for all moves, 1 for only capturing moves
    //char tempBoard[16][14];
    //cpy(tempBoard, board[board_no]);
    int l1 = 0, l2 = 15;
    int b = 0 , w= 0;
    rep(i, 16)
    rep(j, 12)
    {
        if(board[board_no][i][j] == 'H' || board[board_no][i][j] == 'S')
        w++;
        if(board[board_no][i][j] == 'h' || board[board_no][i][j] == 's')
        b++;
    }
    if(b <2 || w< 2)
    return 0;
    if((board[board_no][15][5] >= 'a' && board[board_no][15][5] <= 'z')&& (board[board_no][15][6] >= 'a' && board[board_no][15][6] <= 'z'))
    return 0;
    if((board[board_no][0][5] >= 'A' && board[board_no][0][5] <= 'Z')&& (board[board_no][0][6] >= 'A' && board[board_no][0][6] <= 'Z'))
    return 0;
    if((board[board_no][15][5] >= 'A' && board[board_no][15][5] <= 'Z')|| (board[board_no][15][6] >= 'A' && board[board_no][15][6] <= 'Z'))
    {
        //cout<<"here";
        l1 = 15;
        l2 = 16;
    }
    for(i = l1; i < l2; i++)
    {
        rep(j, 12)
        {
            //cout<<i<<" "<<j<<" "<<endl;
            if(board[board_no][i][j] == 'H')// || board[board_no][i][j] == 'S')
            {
                int pos = moves[board_no][0].size();
                leaping(board_no, i, j);
                tmove.clear();
                tmove.pb(MP(i, j));
                cantering(board_no);
                for(;pos <  moves[board_no][0].size(); pos++)
                {
                    tmove.clear();
                    for(int iter = 0; iter < moves[board_no][0][pos].size(); iter++)
                    tmove.pb(moves[board_no][0][pos][iter]);
                    cantering(board_no);
                }
            }
            else if(board[board_no][i][j] == 'S')
            {
                tmove.clear();
                tmove.pb(MP(i, j));
                cantering(board_no);
            }
        }
    }
    if(moves[board_no][1].size() == 0)
    {
        for(i = l1; i < l2; i++)
        {
        rep(j, 12)
        {
            //cout<<board[board_no][i][j]<<type;
            if(board[board_no][i][j] == 'H' || board[board_no][i][j] == 'S')
            {
                plain(board_no, i, j);
              leaping(board_no, i, j);
            }
        }
        }
        
    //    int pos = random(0, moves[board_no][0].size());
    //    printMove(board_no, 0, pos);
        
    //    rep(i, moves[board_no][0].size())
    {
    //    pos = i;
//    cout<<endl<<endl<<i<<endl;
//    printMove(board_no, 0, pos);
    }
    //cout<<"ty"<<0<<endl;
    return 0;
    }
    
    int pos = random(0, moves[board_no][1].size());
  //  printMove(board_no, 1, pos);
   /* 
    rep(i, moves[board_no][1].size())
    {
        pos = i;
    cout<<endl<<endl<<i<<endl;
    printMove(board_no, 1, pos);
    }
    */
    //cout<<"ty"<<1<<endl;
    return 1;
    /*//type = 1;
    int pos;//;random(0, moves[board_no][type].size());
    //cout<<moves[board_no][1].size()<<" "<<type<<endl;
    rep(i, moves[board_no][type].size())
    {
        pos = i;
    cout<<endl<<endl<<i<<endl;
    printMove(moves[board_no][type][pos].X.X, moves[board_no][type][pos].X.Y, moves[board_no][type][pos].Y.X, moves[board_no][type][pos].Y.Y);
    }
    return type;
    */
}


#include<iostream>
#include<fstream>
#include<string>

int executeMove(int type, int pos, int board_no, int to)
{
    
            ii t;
    int i, j, x, y, iii, jj, ux, uy;
    /*if(executed[type][pos][board_no])
    {
        rep(i, 16)
    {
        rep(j, 12)
        board[to][i][j] = temp[executed[type][pos][board_no]][i][j];
    }
    return 1;
    }
    else
    */
    //    ctrr = min(5*S - 1, ctrr+1);
    //if(to == 4)
        //printMove(board_no, type, pos);
    
    rep(i, 16)
    {
        rep(j, 12)
        board[to][i][j] = board[board_no][i][j];
    }
    int s = moves[board_no][type][pos].size();
    //cout<<s<<endl;;
    if(type == 0)
    {    
        board[to][moves[board_no][type][pos][s - 1].X][moves[board_no][type][pos][s - 1].Y] = board[to][moves[board_no][type][pos][0].X][moves[board_no][type][pos][0].Y];
        board[to][moves[board_no][type][pos][0].X][moves[board_no][type][pos][0].Y] = '-';
    }
    else
    {
        x = moves[board_no][type][pos][0].X;
        y = moves[board_no][type][pos][0].Y;
        char c = board[to][moves[board_no][type][pos][0].X][moves[board_no][type][pos][0].Y];
        board[to][moves[board_no][type][pos][0].X][moves[board_no][type][pos][0].Y] = '-';
        for(i = 1; i < s; i++)
        {
            
            t.X = moves[board_no][type][pos][i].X;
            t.Y = moves[board_no][type][pos][i].Y;        
            ux = (t.X > x)?1:((t.X < x)?-1:0);
            uy = (t.Y > y)?1:((t.Y < y)?-1:0);    
            for(iii = x,  jj = y; iii <= max(x, t.X) && jj <= max(t.Y, y) && iii >= min(x, t.X) && jj >= min(t.Y, y);iii += ux, jj += uy)
            {
                if(board[to][iii][jj] >= 'a' && board[to][iii][jj] <= 'z')
                board[to][iii][jj] = '-';
            }
            board[to][moves[board_no][type][pos][s - 1].X][moves[board_no][type][pos][s - 1].Y] = c;
            x = t.X;
            y = t.Y;
        }
    }
    
    char temp[16][14];
    flipBoard(board[to], temp);
    rep(i, 16)
    {
        rep(j, 12)
        board[to][i][j] = temp[i][j];
    }
    //executed[type][pos][board_no] = ctrr;
    
    return 1;
}

int calc(int board_no)
{

    int wvalue = 0, bvalue = 0, i, j, k, load = 0;
    int b = 0 , w= 0;
    rep(i, 16)
    rep(j, 12)
    {
        if(board[board_no][i][j] == 'H' || board[board_no][i][j] == 'S')
        w++;
        if(board[board_no][i][j] == 'h' || board[board_no][i][j] == 's')
        b++;
    }
    if(b <2)
        wvalue += 10000;
    if(w < 2)
        bvalue += 10000;
    
    if((board[board_no][15][5] >= 'a' && board[board_no][15][5] <= 'z')&& (board[board_no][15][6] >= 'a' && board[board_no][15][6] <= 'z'))
    bvalue += 10000;
    if((board[board_no][0][5] >= 'A' && board[board_no][0][5] <= 'Z')&& (board[board_no][0][6] >= 'A' && board[board_no][0][6] <= 'Z'))
    wvalue += 10000;    
    
    int ctr = 0;
    vector<pair<int, int> > wp;
    vector<pair<int, int> > bp;
    rep(i, 16)
    {
    rep(j, 12)
    {
        //if(board_no == 15)
        //cout<<board[board_no][i][j];
        switch(board[board_no][i][j])
        {
            case 'S':wvalue += 300 + 2*(15 -i);
                        if(i!=0)
                            wp.pb(MP(i, j));
                            break;
            case 'H':wvalue += 500 + 2*(15 -i); ;//+ wboardValue[i][j];
                        if(i!=0)wp.pb(MP(i, j));
                            break;
            case 's':bvalue += 300 +2*i ;// + wboardValue[15 - i][11 - j];
                        if(i!=15)bp.pb(MP(i, j));
                            break;
            case 'h':bvalue += 500 + 2*i;//+ wboardValue[15 - i][11 - j];
                        if(i!=15)bp.pb(MP(i, j));
                            break;
        }
    }
    }
    
    for(i = 0; i <min(2, (int)wp.size()); i++)
    {
        wvalue -= (wp[i].X + min(abs(wp[i].Y - 5), abs(wp[i].Y - 6))/2) * 15;
    }
    for(i = bp.size() - 1; i >= max((int)bp.size()-2, 0); i--)
    {
        bvalue -= (15 - bp[i].X + min(abs(bp[i].Y - 5), abs(bp[i].Y - 6))/2) * 15;
    }
    
    if(bp.size()&&bp[bp.size() - 1].X > 6)
    for(i = wp.size() - 1; i >= max((int)wp.size()-6, 2); i--)
    {
        wvalue -= (14 - wp[i].X + min(abs(wp[i].Y - 5), abs(wp[i].Y - 6))/2) * 8;
    }
    else
        for(i = wp.size() - 1; i >= 2; i--)
    {
        wvalue += (14 - wp[i].X + min(abs(wp[i].Y - 5), abs(wp[i].Y - 6))/2) * 20;
    }
    
    if(wp.size()&&wp[0].X < 10)
    for(i = 0; i <min(7, (int)bp.size() - 2); i++)
    {
        bvalue -= (bp[i].X - 1 + min(abs(bp[i].Y - 5), abs(bp[i].Y - 6))/2) * 8;
    }
    else
        for(i = 0; i < (int)bp.size() - 2; i++)
    {
        bvalue += (bp[i].X - 1 + min(abs(bp[i].Y - 5), abs(bp[i].Y - 6))/2) * 20;
    }

     
    //if(board_no == 8626)
    //cout<<endl<<bvalue<<" "<<wvalue<<endl;;
    
    
    return -wvalue + bvalue;
}




void analyse()
{


    memset(par, -1, sizeof(par));
    int  p = 0, cur, pos, i, x, j, k, dup = 0, smoves;
    
    depth[0] = 0;
    par[0] = -1;
    cur = 0;
    m_type[0] = move(p);
    
    
    
    while(cur < S - 10 && p <= cur)
    {
        
        
        smoves = moves[p][m_type[p]].size();
        /*if(p==-57)
        {cout<<p<<" "<<smoves<<endl;
        rep(i, 16)
        {
            rep(j, 12)
            cout<<board[p][i][j];
            cout<<endl;
        }
        }
        */
        for(i = 0; i < smoves && cur < S - 10; i++)
        {
            cur++;
            
            //
            depth[cur] = depth[p] +1;
            executeMove(m_type[p], i, p, cur);
            //cout<<"exe"<<endl;
            //spe[cur] = executeMove(type, i, p, cur);
            par[cur] = p;
            /*
            if(p == -10)
            {
            cout<<cur<<" "<<p<<" "<<i<<m_type[p]<<endl;
            printMove(p, m_type[p], i);
            for(int i = 0; i < 16; i++)
        {
            rep(j, 12)
            cout<<board[cur][i][j];
            cout<<endl;
        }
        }
        */
        
            m_type[cur] = move(cur);
        
            if(moves[cur][m_type[cur]].size() == 1)
            {
                while(moves[cur][m_type[cur]].size() == 1)
                {
                    /*if(p == -57)
            {
            cout<<"R"<<cur<<" "<<p<<" "<<i<<m_type[p]<<endl;
            printMove(p, m_type[p], i);
            for(int i = 0; i < 16; i++)
        {
            rep(j, 12)
            cout<<board[cur][i][j];
            cout<<endl;
        }
        }
        */
                    depth[cur] += 1;
                    executeMove(m_type[cur], 0, cur, cur);
                //spe[p] = 
                    moves[cur][0].clear();
                    moves[cur][1].clear();
                    m_type[cur] = move(cur);                
            //cout<<p<<endl;
                
                
                    
                
                
                }
            }
                            
        }
        p++;
    }
    //cout<<"here"<<endl;
    for(int t= cur; t > 0; t--)
    {
        if(ans[t][1] == 0)
            {
                x = calc(t);
                if(depth[t] & 1)
                {
                    x = -x;
                    
                }
                else
                {
                    x = x ;
                }
                ans[t][1] = 1;
                ans[t][0] = x;
                
            }
        x = ans[t][0];
            if(depth[par[t]] & 1)
            {
                if(ans[par[t]][1] != 1)
                {
                    ans[par[t]][1] = 1;
                    ans[par[t]][0] = x;
                    
                }
                else if(ans[par[t]][0] < x)
                {
                    ans[par[t]][0] = x;
                    
                }
            }
            else
            {
                if(ans[par[t]][1] != 1)
                {
                    ans[par[t]][1] = 1;
                    ans[par[t]][0] = x;
                    
                }
                else if(ans[par[t]][0]  > x)
                {
                    ans[par[t]][0] = x;                    
                }
            }        
            
    }    
    //dfs(0);
    
    vector<int> pos_moves;
    int mini = 199999999;
    for(i = 1; i <= cur && par[i] == 0; i++)
    {
        if(ans[i][0] < mini && ans[1][1] !=  -1)
        {
            mini = ans[i][0];
            pos_moves.clear();
            pos_moves.pb(i - 1);
        }
        else if(ans[i][0] == mini)
            pos_moves.pb(i - 1);
    }
    
    
    int seed = 0;
    ifstream readfile;
    ofstream writefile;
    string filename = "vish.txt";
    readfile.open( filename.c_str() );
    if( readfile )
    {
        
        readfile>>seed;
        readfile.close();
        
       
        
    }
     srand(seed);
    fprintf(stderr, "sz = %d\n seed = %d", pos_moves.size(), seed);
        //The file doesn't exist
        writefile.open( filename.c_str() );
        //write something to the file
        writefile << rand() << endl;
        writefile.close();
    pos = pos_moves[random(0, pos_moves.size())];

    printMove(0, m_type[0], pos);//moves[0][m_type[0]][pos].X.X, moves[0][m_type[0]][pos].X.Y, moves[0][m_type[0]][pos].Y.X, moves[0][m_type[0]][pos].Y.Y);
}

int main()
{
    input();
    int i, x, j;
    
    analyse();

}
