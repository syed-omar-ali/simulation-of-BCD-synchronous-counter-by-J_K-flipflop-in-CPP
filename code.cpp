#include<graphics.h>
#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;
struct FlipFlop{
    bool J,K,Q;
};
pair<int,int> drawFlipFlop(int centerx,int centery);
void drawAndGate(int centerx,int centery);
void drawORGate(int centerx,int centery);
void paintCircuit();
void init();
void addMouseListener();
FlipFlop flp[4];
vector<pair<int,int> >stats;
bool clockEdge;
int counter = 0;
int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    paintCircuit();
    init();
    addMouseListener();
    closegraph();
}
void init(){
    for(int i=0;i<4;i++)
        flp[i].Q = false;
    flp[0].J = true;
    flp[0].K = true;
}
void paintCircuit(){
    //BASIC DESIGN STARTS
    pair<int,int> qcor1 = drawFlipFlop(150,300);
    drawAndGate(qcor1.first+100,qcor1.second+15);
    pair<int,int> qcor2 = drawFlipFlop(450,300);
    drawAndGate(qcor2.first+100,qcor2.second+15);
    pair<int,int> qcor3 = drawFlipFlop(750,300);
    drawAndGate(qcor3.first+100,qcor3.second+15);
    drawAndGate(qcor3.first+100,qcor3.second-70);
    drawORGate(qcor3.first+200,qcor3.second-(70-15)/2-3);
    pair<int,int> qcor4 = drawFlipFlop(1150,300);
    //BASIC DESIGN ENDS
    //LINES
    //CLK
    line(15,450,1050,450);
    line(1050,450,1050,300);
    line(1050,300,1100,300);
    line(650,450,650,300);
    line(650,300,700,300);
    line(350,450,350,300);
    line(350,300,400,300);
    line(50,450,50,300);
    line(50,300,100,300);
    //CLK
    //GATE CONNECTIONS
    line(150+50,qcor1.second+8,qcor1.first+100-24/2,qcor1.second+8);
    line(450+50,qcor2.second+22,qcor2.first+100-24/2,qcor2.second+22);
    line(750+50,qcor3.second+22,qcor3.first+100-24/2,qcor3.second+22);
    line(qcor1.first+100-24/2-25,qcor1.second+22,qcor1.first+100-24/2,qcor1.second+22);
    line(qcor1.first+100-24/2-25,qcor1.second+22,qcor1.first+100-24/2-25,480);
    line(qcor1.first+100-24/2-25,480,1250,480);
    line(1250,480,1250,300+150/2-25);
    line(1250,300+150/2-25,1200,300+150/2-25);
    line(qcor1.first+123,qcor1.second+15,400,qcor1.second+15);
    line(qcor2.first+123,qcor2.second+15,700,qcor2.second+15);
    line(qcor3.first+123,qcor3.second+15,qcor3.first+150,qcor3.second+15);
    line(qcor3.first+150,qcor3.second+15,qcor3.first+150,qcor3.second+15-35);
    line(qcor3.first+150,qcor3.second+15-35,qcor3.first+216,qcor3.second+15-35);
    line(qcor3.first+123,qcor3.second-70,qcor3.first+150,qcor3.second-70);
    line(qcor3.first+150,qcor3.second-70,qcor3.first+150,qcor3.second-70+30);
    line(qcor3.first+150,qcor3.second-70+30,qcor3.first+216,qcor3.second-70+30);
    line(qcor3.first+250,qcor3.second-(70-15)/2-3-1,qcor3.first+300,qcor3.second-(70-15)/2-3-1);
    line(qcor3.first+300,qcor3.second-(70-15)/2-3-1,qcor3.first+300,300+150/2-20);
    line(qcor3.first+300,300+150/2-20,1100,300+150/2-20);
    line(qcor3.first+300,qcor4.second+16,1100,qcor4.second+16);
    line(qcor3.first+100-24/2,qcor3.second-70-8,qcor3.first+100-24/2-20,qcor3.second-70-8);
    line(qcor3.first+100-24/2-20,qcor3.second-70-8,qcor3.first+100-24/2-20,qcor3.second-70-8-30);
    line(qcor3.first+100-24/2-20,qcor3.second-70-8-30,1250,qcor3.second-70-8-30);
    line(qcor3.first+100-24/2,qcor3.second-70+8,qcor1.first+100-24/2-25,qcor3.second-70+8);
    line(qcor1.first+100-24/2-25,qcor3.second-70+8,qcor1.first+100-24/2-25,qcor1.second+8);
    line(450+50+35,qcor2.second+8,qcor2.first+100-24/2,qcor2.second+8);
    line(450+50+35,qcor2.second+8,450+50+35,qcor3.second-70+8);
    line(750+50+35,qcor3.second+8,qcor3.first+100-24/2,qcor3.second+8);
    line(750+50+35,qcor3.second+8,750+50+35,qcor3.second+8-50);
    line(750+50+35,qcor3.second+8-50,750+50+35-170,qcor3.second+8-50);
    line(750+50+35-170,qcor3.second+8-50,750+50+35-170,300+150/2-30+7);
    line(750+50+35-170,300+150/2-30+7,750-50,300+150/2-30+7);

    //GATE CONNECTIONS
    //OUTPUT
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    line(1200,qcor4.second,1250,qcor4.second);
    line(1250,qcor4.second,1250,50);
    outtextxy(1250-20,50-10,"Q4");
    line(750+20+50,qcor3.second+22,750+20+50,50);
    outtextxy(750+20+50-20,50-10,"Q3");
    line(150+20+50,qcor1.second+8,150+20+50,50);
    outtextxy(150+20+50-20,50-10,"Q1");
    line(450+20+50,qcor2.second+22,450+20+50,50);
    outtextxy(450+20+50-20,50-10,"Q2");
    //OUTPUT
    //OTHERS
    line(qcor1.first+123+70,qcor1.second+15,qcor1.first+123+70,300+150/2-20);
    line(qcor1.first+123+70,300+150/2-20,450-50,300+150/2-20);
    line(15,300-150/2+25,150-50,300-150/2+25);
    line(30,300-150/2+25,30,300+150/2-15);
    line(30,300+150/2-15,150-50,300+150/2-15);
    //OTHERS
    //CLOCK
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR,1);
    outtextxy(5,440,"CLK");
    rectangle(5,440,40,460);
    //CLOCK
    //STATS
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR,3);
    outtextxy(10,530,"CLK");
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR,1);
    char s[1];
    s[0] = counter + '0';
    s[1] = '\0';
    outtextxy(90+5,553-19-25,s);
    line(70,553,90,553);
    line(90,553,90,553-19);
    line(90,553-19,90+20,553-19);
    stats.push_back(make_pair(90+20,553-19));
    clockEdge = false;
    outtextxy(10,555+5,"Q1");
    line(70,555+5+23,90+20,555+5+23);
    stats.push_back(make_pair(90+20,555+5+23));
    outtextxy(10,580+5+5,"Q2");
    line(70,580+5+23,90+20,580+5+23);
    stats.push_back(make_pair(90+20,580+5+23));
    outtextxy(10,605+5+5+5,"Q3");
    line(70,605+5+23,90+20,605+5+23);
    stats.push_back(make_pair(90+20,605+5+23));
    outtextxy(10,630+5+5+5+5,"Q4");
    line(70,630+5+23,90+20,630+5+23);
    stats.push_back(make_pair(90+20,630+5+23));
    //STATS
    //getch();
}
pair<int,int> drawFlipFlop(int centerx,int centery){
    int width = 100;
    int height = 150;
    int topLeftx = centerx-width/2;
    int topLefty = centery-height/2;
    int bottomRightx = centerx+width/2;
    int bottomRighty = centery+height/2;
    rectangle(topLeftx,topLefty,bottomRightx,bottomRighty);
    int jx = topLeftx + 10;
    int jy = topLefty + 10;
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    outtextxy(jx,jy,"J");
    int kx = topLeftx + 10;
    int ky = topLefty + height - 36;
    outtextxy(kx,ky,"K");
    int qx = topLeftx + width - 27;
    int qy = topLefty + 10;
    outtextxy(qx,qy,"Q");
    int qbarx = topLeftx + width - 27;
    int qbary = topLefty + height - 34;
    line(qbarx,qbary-1,qbarx+20,qbary-1);
    outtextxy(qbarx,qbary,"Q");
    int clkx = kx;
    int clky = (jy+ky)/2;
    clky += 8;
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
    outtextxy(clkx,clky,"CLK");
    pair<int,int>  qcor = make_pair(qx,qy);
    return qcor;
}
void drawAndGate(int centerx,int centery){
    int width,height;
    width = height = 24;
    line(centerx-width/2,centery-height/2,centerx-width/2,centery+height/2);
    line(centerx-width/2,centery-height/2,centerx+width/2-1,centery-height/2);
    line(centerx-width/2,centery+height/2,centerx+width/2,centery+height/2);
    arc(centerx+width/2,centery,-90,100,height/2);
}
void drawORGate(int centerx,int centery){
    arc(centerx,centery,290,70,20);
    arc(centerx,centery+60,50,90,80);
    arc(centerx,centery-60,272,311,80);
}
void onclock(){
    setcolor(WHITE);
    if(!clockEdge){
        counter = (counter+1)%10;
        bool q[4];
        for(int i=0;i<4;i++)
            q[i] = flp[i].Q;
        flp[0].Q = ((flp[0].J)&(~q[0])) | ((~flp[0].K)&(q[0]));
        flp[1].Q = (((q[0])&(~q[3]))&(~q[1])) | ((~((q[0])&(~q[3])))&(q[1]));
        flp[2].Q = ((q[1]&q[0])&(~q[2])) | ((~(q[1]&q[0]))&(q[2]));
        flp[3].Q = (((q[2]&(q[1]&q[0])) | (q[0]&q[3])) & (~q[3])) | ((~((q[2]&(q[1]&q[0])) | (q[0]&q[3]))) & (q[3]));
        for(int i=3;i>=0;i--){
            cout << flp[i].Q << " ";
        }
        line(stats[0].first,stats[0].second,stats[0].first,stats[0].second+19);
        stats[0].second += 19;
        clockEdge = true;
    }else{
        line(stats[0].first,stats[0].second,stats[0].first+20,stats[0].second);
        stats[0].first += 20;
        line(stats[0].first,stats[0].second,stats[0].first,stats[0].second-19);
        stats[0].second -= 19;
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR,1);
        char s[1];
        s[0] = counter + '0';
        s[1] = '\0';
        outtextxy(stats[0].first+5,stats[0].second-25,s);
        //stats[0].second += 19;
        line(stats[0].first,stats[0].second,stats[0].first+20,stats[0].second);
        stats[0].first += 20;
        clockEdge = false;
    }
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    if(flp[0].Q){
        bar(stats[1].first,stats[1].second-19,stats[1].first+20,stats[1].second+1);
        stats[1].first += 20;
        setcolor(BROWN);
    }
    else{
        setcolor(WHITE);
        line(stats[1].first,stats[1].second,stats[1].first+20,stats[1].second);
        stats[1].first += 20;
    }
    outtextxy(150+20+50-20,50-10,"Q1");
    if(flp[1].Q){
        bar(stats[2].first,stats[2].second-19,stats[2].first+20,stats[2].second+1);
        stats[2].first += 20;
        setcolor(BROWN);
    }
    else{
        setcolor(WHITE);
        line(stats[2].first,stats[2].second,stats[2].first+20,stats[2].second);
        stats[2].first += 20;
    }
    outtextxy(450+20+50-20,50-10,"Q2");
    if(flp[2].Q){
        bar(stats[3].first,stats[3].second-19,stats[3].first+20,stats[3].second+1);
        stats[3].first += 20;
        setcolor(BROWN);
    }
    else{
        setcolor(WHITE);
        line(stats[3].first,stats[3].second,stats[3].first+20,stats[3].second);
        stats[3].first += 20;
    }
    outtextxy(750+20+50-20,50-10,"Q3");
    if(flp[3].Q){
        bar(stats[4].first,stats[4].second-19,stats[4].first+20,stats[4].second+1);
        stats[4].first += 20;
        setcolor(BROWN);
    }
    else{
        setcolor(WHITE);
        line(stats[4].first,stats[4].second,stats[4].first+20,stats[4].second);
        stats[4].first += 20;
    }
    outtextxy(1250-20,50-10,"Q4");
    cout << endl;
}
void addMouseListener(){
    while(1){
        int xcor = mousex();
        int ycor = mousey();
        delay(50);
        if(ismouseclick(WM_LBUTTONUP) && (xcor>=5 && xcor<=40 && ycor>=440 && ycor<=460)){
            onclock();
        }
        clearmouseclick(WM_LBUTTONUP);
    }
}
