/*
--------------------------------------------------------

   练习4.4
        一份"用户概况记录(user profile)" 内含以下数据:
    登录记录, 实际姓名, 登入次数, 猜过次数, 猜对次数,
    等级——包括初级, 中级, 高级, 专家, 以及猜对百分比(可实
    时计算获得, 或将其值储存起来备用). 请写出一个名为UserProfile
    的class,　提供以下操作: 输入, 输出, 相等测试, 不等测试.
    其constructorb必须能够处理默认的用户等级, 默认的登录名称
    ("guest"). 对于同样名为guest的多个用户, 你如何保证每个guest
    有他自己独有的登录会话(login session), 不会和其他人混淆?

--------------------------------------------------------
*/
#include "test4_4_userprofile.h"
#include <iostream>
#include <string>


using namespace std;

int main()
{
    UserProfile upf;
    cout << upf;
    UserProfile upf1;
    cout << upf1;

    UserProfile liky("Liky", UserProfile::Guru);
    cout << liky;
    liky.addLoginTimes();
    liky.addGuessTimes(50);
    liky.addGuessRightTimes(20);
    cout << liky;

    return 0;
}