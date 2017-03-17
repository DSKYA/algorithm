#include<iostream>
#include<string>
using namespace std;
struct Category{
    string name;
    int level;
};
struct Role{
    string roleName;
    struct Category roleCategory[11];
    int categoryNum;
};
struct User{
    string userName;
    struct Role userRole[11];
    int roleNum;
};
struct Category cate[101];
struct Role role[101];
struct User user[101];
int p,r,u,q;
struct Category getCategory(string s){
    int index;
    struct Category c;
    if((index = s.find(":",0))!= string::npos){
        c.name = s.substr(0,index);
        c.level = s.at(s.length()-1)-'0';
    }else{
        c.name = s;
        c.level = -1;
    }
    return c;
}
int findUser(string name){
    int i;
    for(i = 0; i < u; i++){
        if(user[i].userName == name){
            return i;
        }
    }
    return -1;
}
int findRole(string roleName){
    int i;
    for(i = 0; i < r; i++){
        if(role[i].roleName == roleName){
            return i;
        }
    }
    return -1;
}
void findCategory(struct User oneUser,string quanxian){
    int i,j;
    string quanxianName;
    int flag = 0;
    int level,index,maxLevel = -1;
    if((index = quanxian.find(":",0))!=string::npos){
        quanxianName = 	quanxian.substr(0,index);
        level = quanxian.at(quanxian.length()-1)-'0';
    }else{
        quanxianName = quanxian;
        level = -1;
    }
    for(i = 0; i < oneUser.roleNum; i++){
        struct Role oneRole = oneUser.userRole[i];
        for(j = 0; j < oneRole.categoryNum; j++){
            struct Category oneCategory = oneRole.roleCategory[j];
            // 不分等级权限的不分等级查询
            if(oneCategory.name == quanxianName && oneCategory.level == level && level == -1){
                flag = 1;
            }
            //  分等级权限带等级查询
            if(oneCategory.name == quanxianName && level != -1 && oneCategory.level >= level){
                flag = 1;
            }
            //  分等级权限不带等级查询
            if(level == -1 && oneCategory.level != -1 && quanxianName == oneCategory.name){
                if(oneCategory.level > maxLevel){
                    maxLevel = oneCategory.level;
                    flag = 2;
                }
            }
        }
    }
    if(flag == 1){
        cout<<"true"<<endl;
    }
    if(flag == 2){
        cout<<maxLevel<<endl;
    }
    if(flag == 0){
        cout<<"false"<<endl;
    }
}
int main(){
    int i,j;
    string s;
    cin>>p;
    // 输入权限
    for(i = 0; i < p; i++){
        cin>>s;
        cate[i] = getCategory(s);
    }
    cin>>r;
    //输入角色
    for(i = 0; i < r; i++){
        cin>>role[i].roleName;
        cin>>role[i].categoryNum;
        // 遍历输入角色的每个权限
        for(j = 0; j < role[i].categoryNum; j++){
            cin>>s;
            role[i].roleCategory[j] = getCategory(s);
        }
    }
    cin>>u;
    //输入用户
    for(i = 0; i < u; i++){
        cin>>user[i].userName;
        cin>>user[i].roleNum;
        int index;
        for(j = 0; j < user[i].roleNum; j++){
            cin>>s;
            if((index = findRole(s))!= -1){
                user[i].userRole[j] = role[index];
            }
        }
    }
    cin>>q;
    //开始查询
    while(q--){
        string name;
        string quanxian;
        cin>>name>>quanxian;
        int index;
        //用户查询
        if((index = findUser(name))!= -1){	//找到用户
            struct User oneUser = user[index];
            findCategory(oneUser,quanxian);
        }else{
            cout<<"false"<<endl;
        }
    }
    return 0;
}