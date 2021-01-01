/*
--------------------------------------------------------

        一份"用户概况记录(user profile)" 内含以下数据:
    登录记录, 实际姓名, 登入次数, 猜过次数, 猜对次数,
    等级——包括初级, 中级, 高级, 专家, 以及猜对百分比(可实
    时计算获得, 或将其值储存起来备用)

--------------------------------------------------------
*/

//目前只能用MSVC编译
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <array>


class UserProfile
{

public:

    enum uLevel { Beginner, Intermediate, Advanced, Guru }; //等级分类
    std::array<std::string, 4> arrayLevel = { "Beginner", "Intermediate", "Advanced", "Guru" };
    UserProfile(); //guest登录
    UserProfile(std::string login, uLevel = Beginner); //带login登录


    //读数据
    std::string getLogin() const { return _login; } //获取登录ID
    std::string getLoginName() const { return _login_name; } //获取真实姓名
    int getLoginTimes() const { return _login_times; } //获取登录次数
    int getGuessTimes() const { return _guess_times; } //获取猜测次数
    int getGuessRightTimes() const { return _guess_right_times; } //获取猜对次数
    double getGuessAverage() const;  //获取猜对百分比
    std::string getUserLevel() const { return arrayLevel[_user_level] ;} //获取等级


    //写数据
    void setUserName(std::string username) { _login_name = username; }
    void addLoginTimes(int cnt = 1) {  _login_times += cnt; }
    void addGuessTimes(int cnt = 1) { _guess_times += cnt; }
    void addGuessRightTimes(int cnt = 1) { _guess_right_times += cnt; }



private:
    std::string _login; //登录ID
    std::string _login_name; //真实姓名
    int _login_times; //登录次数
    int _guess_times; //猜测次数
    int _guess_right_times; //猜对次数
    double _guess_average; //猜对百分比
    uLevel _user_level; //等级

    static std::map<std::string, uLevel> _level_map;

};

//重写<<操作符，输出用户信息
std::ostream& operator<<(std::ostream &os, const UserProfile &rhs)
{
    os << rhs.getLogin() << " "
       << rhs.getUserLevel() << " "
       << rhs.getLoginTimes() << " "
       << rhs.getGuessTimes() << " "
       << rhs.getGuessRightTimes() << " "
       << rhs.getGuessAverage() << std::endl;
    return os;
}

//guest登录
inline UserProfile::UserProfile()
    : _login("guest"), _user_level(Intermediate),
    _login_times(1), _guess_times(0), _guess_right_times(0)
{
    //guest后带唯一id数 组合成 唯一标识符
    static int id = 0;
    char buffer[16];
    _itoa_s(id++, buffer, 10);
    _login += buffer;
}

//带login登录
inline UserProfile::UserProfile(std::string login, uLevel level)
    : _login(login), _user_level(level),
    _login_times(1), _guess_times(0), _guess_right_times(0) {}

//获取猜对百分比
inline double UserProfile::getGuessAverage() const
{
    return _guess_times ? double ( _guess_right_times ) / double ( _guess_times ) * 100
                        : 0.0;
}

