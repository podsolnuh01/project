#include "TXLib.h"

struct Button
{
    int x;
    int y;
    int w;
    int h;
    const char* text;
    bool visible;

    void draw()
    {
        if(visible)
        {
            txSetColor (TX_WHITE, 3);
            txSetFillColor (TX_RED);
            Win32::RoundRect (txDC(), x, y, x+w, y+h, 30, 30);
            txSelectFont("Times New Roman", 30);
            txDrawText(x, y, x+w, y+h, text);
        }
    }

    bool click()
    {
        return  (txMouseX()>x && txMouseX()<x+w &&
                 txMouseY()>y && txMouseY()<y+h &&
                 txMouseButtons() == 1 && visible);
    }
};

int main()
{
txCreateWindow (800, 600);
txTextCursor (false);

string PAGE = "menu";

Button btn[5];
btn[0] = {100, 100, 200, 40, "�����", true};
btn[1] = {100, 150, 200, 40, "���������", true};
btn[2] = {100, 200, 200, 40, "�������", true};
btn[3] = {100, 250, 200, 40, "�����", true};

    while(!btn[3].click())
    {
        txClear();
        txBegin();
//����
        if(PAGE=="menu")
        {
            for(int i=0; i<4; i++)
            {
                btn[i].draw();
            }

            if(btn[0].click())
            {
                while(btn[0].click()) txSleep(50);
                PAGE="game";
                for(int i=0; i<4; i++)
                {
                    btn[i].visible = false;
                }
            }
            if(btn[1].click())
            {
                while(btn[1].click()) txSleep(50);
                PAGE="nastr";
                for(int i=0; i<4; i++)
                {
                    btn[i].visible = false;
                }
            }
            if(btn[2].click())
            {
                while(btn[2].click()) txSleep(50);
                PAGE="rules";
                for(int i=0; i<4; i++)
                {
                    btn[i].visible = false;
                }
            }


            txSetFillColor (TX_BLACK);
        }

//���������
        if(PAGE=="nastr")
        {
            txSetColor(TX_BLACK);
            txTextOut(0, 0, "�������� ���������");
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE="menu";
                for(int i=0; i<=4; i++)
                {
                    btn[i].visible = true;
                }
            }


            txSetFillColor (TX_BLUE);
        }

//�������
        if(PAGE=="rules")
        {
            txSetColor(TX_BLACK);
            txTextOut(0, 0, "�������");
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE="menu";
                for(int i=0; i<=4; i++)
                {
                    btn[i].visible = true;
                }
            }


            txSetFillColor (TX_YELLOW);
        }

//���a
        if(PAGE=="game")
        {
            txTextOut(0, 0, "����");
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE="menu";
                for(int i=0; i<=4; i++)
                {
                    btn[i].visible = true;
                }
            }
            txSetFillColor (TX_WHITE);
        }


    txEnd();
    txSleep(10);

    }




txDisableAutoPause();
return 0;
}
