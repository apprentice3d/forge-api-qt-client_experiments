#pragma once

#include <QObject>
#include "bearer.h"

namespace Forge {

class BaseApi : public QObject
{
	Q_OBJECT

public:
    BaseApi(QObject *parent = nullptr);
	virtual ~BaseApi() = 0;

	virtual void getTokenWithScope(QString scope) = 0;

	QString get_host() const;
	void set_host(const QString& host);
	QString get_authenticate_endpoint() const;
	void set_authenticate_endpoint(const QString& endpoint);
protected:
	QString m_host;
	QString m_endpoint;

};


inline QString writeScope(int num, ...)
{
	QString result = "";
	va_list arguments;
	va_start(arguments, num);
	for (int i = 0; i < num; ++i)
	{
		result += scopes.at(va_arg(arguments, int)) + " ";
	}
	va_end(arguments);

	return result;
}

template <class ... Scopes>
QString setScopes(Scopes... arg)
{
	const int n = sizeof...(Scopes);
	
	return n > 0 ? Forge::writeScope(n, arg...) : QString("");
}

}
