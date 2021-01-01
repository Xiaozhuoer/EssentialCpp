/*
--------------------------------------------------------

        һ��"�û��ſ���¼(user profile)" �ں���������:
    ��¼��¼, ʵ������, �������, �¹�����, �¶Դ���,
    �ȼ�������������, �м�, �߼�, ר��, �Լ��¶԰ٷֱ�(��ʵ
    ʱ������, ����ֵ������������)

--------------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <array>


class UserProfile
{

public:

    enum uLevel { Beginner, Intermediate, Advanced, Guru }; //�ȼ�����
    std::array<std::string, 4> arrayLevel = { "Beginner", "Intermediate", "Advanced", "Guru" };
    UserProfile(); //guest��¼
    UserProfile(std::string login, uLevel = Beginner); //��login��¼


    //������
    std::string getLogin() const { return _login; } //��ȡ��¼ID
    std::string getLoginName() const { return _login_name; } //��ȡ��ʵ����
    int getLoginTimes() const { return _login_times; } //��ȡ��¼����
    int getGuessTimes() const { return _guess_times; } //��ȡ�²����
    int getGuessRightTimes() const { return _guess_right_times; } //��ȡ�¶Դ���
    double getGuessAverage() const;  //��ȡ�¶԰ٷֱ�
    std::string getUserLevel() const { return arrayLevel[_user_level] ;} //��ȡ�ȼ�


    //д����
    void setUserName(std::string username) { _login_name = username; }
    void addLoginTimes(int cnt = 1) {  _login_times += cnt; }
    void addGuessTimes(int cnt = 1) { _guess_times += cnt; }
    void addGuessRightTimes(int cnt = 1) { _guess_right_times += cnt; }



private:
    std::string _login; //��¼ID
    std::string _login_name; //��ʵ����
    int _login_times; //��¼����
    int _guess_times; //�²����
    int _guess_right_times; //�¶Դ���
    double _guess_average; //�¶԰ٷֱ�
    uLevel _user_level; //�ȼ�

    static std::map<std::string, uLevel> _level_map;

};

//��д<<������������û���Ϣ
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

//guest��¼
inline UserProfile::UserProfile()
    : _login("guest"), _user_level(Intermediate),
    _login_times(1), _guess_times(0), _guess_right_times(0)
{
    //guest���Ψһid�� ��ϳ� Ψһ��ʶ��
    static int id = 0;
    char buffer[16];
    _itoa_s(id++, buffer, 10);
    _login += buffer;
}

//��login��¼
inline UserProfile::UserProfile(std::string login, uLevel level)
    : _login(login), _user_level(level),
    _login_times(1), _guess_times(0), _guess_right_times(0) {}

//��ȡ�¶԰ٷֱ�
inline double UserProfile::getGuessAverage() const
{
    return _guess_times ? double ( _guess_right_times ) / double ( _guess_times ) * 100
                        : 0.0;
}

