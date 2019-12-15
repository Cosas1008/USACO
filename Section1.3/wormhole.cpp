/*
ID: yuweiic1
LANG: C++
TASK: wormhole
*/

#include<iostream>
#include<fstream>

using namespace std;
struct position
{
    int x;
    int y;
};
int pairing(struct position*  p, int num)
{

    return 0;
};

int main()
{
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    int wormholes;
    int ans;
    fin >> wormholes;
    position pos[wormholes];
    for(int i = 0; i < wormholes; i++)
    {
        int x,y;
        position ps;
        fin >> x >> y;
        ps.x = x;
        ps.y = y;
        pos[i] = ps;
    }
    ans = pairing(pos,wormholes);
    fout << ans << endl;
    fin.close();
    fout.close();
    return 0;
}