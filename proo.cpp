#include "pch.h"

int run(int year)//闰年判断
{
	if (year % 4 == 0 && year % 100 != 0)
		return 1;
	else
		return 0;
}
int month_s(int year,int month)//每个月的天数计算
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (month == 2)
	{
		if (run(year) == 1)
			return 29;
		else
			return 28;
	}
	else
		return 30;
}
int day_di(int year, int month, int day)
{
	int zong = 365;
	if (run(year) == 1)//闰年
		zong = 366;
	int dayy = 0;
	for (int i = 1; i < month; i++)
		dayy += month_s(year, month);
	dayy += day;
	return dayy;

}
int day_sheng(int year, int month, int day)
{
	int zong = 365;
	if (run(year) == 1)//闰年
		zong = 366;
	int dayy = 0;
	for (int i = 1; i < month; i++)
		dayy += month_s(year, month);
	dayy += day;
	return zong-dayy;

}
int cha(int year1, int month1, int day1, int year2,int month2, int day2)
{
	int cha = 0;

	if (year1 == year2)//同一年
	{
		int cha1 = day_sheng(year1,month1,day1);
		int cha2 = day_sheng(year2, month2, day2);
		return cha1 - cha2;
	}
	else if(year2-year1==1)//差1年
	{
		int cha1 = day_sheng(year1, month1, day1);
		int cha2 = day_di(year2, month2, day2);
		return cha1 + cha2;
	}
	else//差很多年
	{
		int cha1 = day_sheng(year1, month1, day1);
		int cha2 = day_di(year2, month2, day2);
		for (int i = year1 + 1; i < year2; i++)
		{
			if (run(year1) == 1)//润
				cha2 += 366;
			else
				cha2 += 365;
		}
		return cha1 + cha2;
	}
	//cha = (year2 - year1) * 365 + (month2 - month1) * 30 + (day2 - day1);
	return cha;
}