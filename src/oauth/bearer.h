#pragma once

#include <QStringList>
#include <QJsonDocument>
#include <QJsonObject>

namespace Forge {

	static QStringList scopes = {
		"data:read",
		"data:write",
		"data:create",
		"data:search",
		"bucket:create",
		"bucket:read",
		"bucket:update",
		"bucket:delete",
		"code:all",
		"account:read",
		"account:write",
		"user-profile:read",
	};


	namespace DATA {
		enum {
			READ = 0,
			WRITE,
			CREATE,
			SEARCH,
			LAST
		};
	}


	namespace BUCKET {
		enum {
			CREATE = static_cast<int>(DATA::LAST),
			READ,
			UPDATE,
			DELETE,
			LAST

		};
	}


	namespace CODE {
		enum {
			ALL = static_cast<int>(BUCKET::LAST),
			LAST
		};
	}

	namespace ACCOUNT {
		enum {
			READ = static_cast<int>(CODE::LAST),
			WRITE,
			LAST
		};
	}

	namespace USER_PROFILE {
		enum {
			READ = static_cast<int>(ACCOUNT::LAST),
				LAST
		};
	}













enum class TOKEN_CONTEXT
{
	TWO_LEGGED = 2,
	THREE_LEGGED
};

//enum class DATA
//{
//	READ = 0,
//	WRITE,
//	CREATE,
//	SEARCH,
//	LAST
//};
//
//
//enum class BUCKET
//{
//	CREATE = static_cast<int>(DATA::LAST),
//	READ,
//	UPDATE,
//	DELETE,
//	LAST
//
//};
//
//enum class CODE
//{
//	ALL = static_cast<int>(BUCKET::LAST),
//	LAST
//};
//
//enum class ACCOUNT
//{
//	READ = static_cast<int>(CODE::LAST),
//	WRITE,
//	LAST
//};
//
//enum class USER_PROFILE
//{
//	READ = static_cast<int>(ACCOUNT::LAST),
//	LAST
//};





class Bearer
{
public:
    Bearer(QString json_data = nullptr);
    ~Bearer();

	void init();

	QString* get_token_type() const;
	void set_token_type(QString* const token_type);
	qint32 get_expiration_time() const;
	void set_expiration_time(const qint32 expires_in);
	QString* get_access_token() const;
	void set_access_token(QString* const access_token);
	QString* get_refresh_token() const;
	void set_refresh_token(QString* const refresh_token);
	TOKEN_CONTEXT get_token_context() const;
	void set_token_context(const TOKEN_CONTEXT token_context);

private:
    QString* m_token_type;
    qint32 m_expires_in;
    QString* m_access_token;
    // for 3-legged only
    QString* m_refresh_token;
	TOKEN_CONTEXT m_token_context;

};
}
