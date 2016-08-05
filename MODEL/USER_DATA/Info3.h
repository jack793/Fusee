#ifndef INFO3_H
#define INFO3_H

#include<QXmlStreamReader>
#include<QString>
#include<vector>

class Info3{
private:
    std::vector<const QString> followers;
    std::vector<const QString> following;
    QString level;
public:
    Info3(const std::vector<const QString> &flwe=std::vector<const QString>(), 
          const std::vector<const QString> &flwi=std::vector<const QString>(), const Qstring& lev="");
    
    const std::vector<const QString>& getFollowers() const;
    const std::vector<const QString>& getFollowing() const;
    const QString& getLevel() const;
    
    void setFollowers(const std::vector<const QString>& flwe);
    void setFollowing(const std::vector<const QString>& flwi);
    void setLevel(const QString& lev);
    
    void addFollower(const QString& flwe);
    void addFollowing(const QString& flwi);
    
    bool matchFollower(const QString& text) const;
    bool matchFollowing(const QString& text) const;
    
    static Info3 readInfo3(QXmlStreamReader& );
};

#endif // INFO3_H
