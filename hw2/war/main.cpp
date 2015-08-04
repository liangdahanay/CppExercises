// W3-编程作业-魔兽世界之1-备战.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <cstring>
using std::cin;
using std::string;
using std::cout;
using std::endl;
//using namespace std;

int wlf[5];//dragon 、ninja、iceman、lion、wolf 的初始生命值
string wrname[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };

class HeadQ
{
	int lifen;//生命元
	int wno;//武士的最大编号
	int worrior[5];//5个武士依次的数量
	string name;
	bool stop;//是否停止制造武士

public :
	HeadQ(int lfn = 0, string snm = "") :lifen(lfn), wno(0), name(snm), stop(0)
	{
		memset(worrior,0,sizeof(worrior));
	}

	bool gen_wr(int time, int k)//生成编号为k的武士
	{
		if (lifen < wlf[k])
		{
			return false;
		}
		wno++;
		worrior[k]++;
		lifen = lifen - wlf[k];
		cout.fill('0');//设置填充字符，一直有效
		cout.width(3);//设域宽为3，一次有效
		cout << time << " " << name <<" "<<wrname[k]<< " " << wno << " born with strength " << wlf[k] << ","
			<< worrior[k] << " " << wrname[k] << " in " << name << " headquarter" << endl;
		
		return true;
	}

	bool is_stop(int time)
	{
		bool flag = 0;//标志是否可以继续制造武士
		for (int i = 0; i < 5; ++i)
		{
			if (lifen >= wlf[i]) { flag = 1; break; }//只要还可以制造一个武士
		}
		if (flag == 0)
		{
			cout.fill('0');//设置填充字符，一直有效
			cout.width(3);//设域宽为3，一次有效
			cout << time << " " << name << " headquarter stops making warriors" << endl;
			stop = true;
			return true;
		}
		return false;
	}

	bool getstopflag(void)
	{
		return stop;
	}
};

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n;++i)
	{
		cout << "Case:" << i << endl;
		int m;
		cin >> m;
		cin >> wlf[0] >> wlf[1] >> wlf[2] >> wlf[3] >> wlf[4];
		HeadQ redhq(m,"red");//红方按iceman、lion、wolf、ninja、dragon顺序:2,3,4,1,0
		HeadQ bluehq(m,"blue");//蓝方按lion、dragon、ninja、iceman、wolf顺序:3,0,1,2,4
		int redsx[5] = {2,3,4,1,0};
		int bluesx[5] = { 3, 0, 1, 2, 4 };

		int time = 0;
		int redk = 0;
		int bluek = 0;
		while (redhq.getstopflag() == false || bluehq.getstopflag() == false)
		{
			while (redhq.getstopflag()==false && redhq.is_stop(time)==false && redhq.gen_wr(time, redsx[redk]) == false)//当没有停止生成武士且生成武士失败时，生成下一个可生成的武士
			{
				redk = (redk + 1) % 5;
			}
			redk = (redk + 1) % 5;

			while (bluehq.getstopflag()==false && bluehq.is_stop(time)==false && bluehq.gen_wr(time, bluesx[bluek]) == false)//当没有停止生成武士且生成武士失败时，生成下一个可生成的武士
			{
				bluek = (bluek + 1) % 5;
			}
			bluek = (bluek + 1) % 5;

			time++;
		}
	}
	return 0;
}
