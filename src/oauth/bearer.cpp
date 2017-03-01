#include "bearer.h"
#include <qobject.h>


/**
 * \brief Holds data on received token
 */
Forge::Bearer::Bearer(QString json_data)
{
	this->init();
	if (json_data != nullptr)
	{
		QJsonDocument data = QJsonDocument::fromJson(json_data.toUtf8());
		QJsonObject json_object = data.object();
		this->m_token_type = new QString(json_object["token_type"].toString());
		this->m_expires_in = json_object["expires_in"].toInt();
		this->m_access_token = new QString(json_object["access_token"].toString());
		this->m_refresh_token = new QString(json_object["refresh_token"].toString());
	}
}

void Forge::Bearer::init()
{
	m_token_type = new QString("");
	m_expires_in = 0;
	m_access_token = new QString("");
	m_refresh_token = new QString("");
	m_token_context = TOKEN_CONTEXT::TWO_LEGGED;
}

Forge::Bearer::~Bearer()
{
	if (m_token_type != nullptr) { delete m_token_type; }
	if (m_access_token != nullptr) { delete m_access_token; }
	if (m_refresh_token != nullptr) { delete m_refresh_token; }
}



QString* Forge::Bearer::get_token_type() const
{
	return m_token_type;
}

void Forge::Bearer::set_token_type(QString* const token_type)
{
	this->m_token_type = token_type;
}

qint32 Forge::Bearer::get_expiration_time() const
{
	return m_expires_in;
}

void Forge::Bearer::set_expiration_time(const qint32 expires_in)
{
	this->m_expires_in = expires_in;
}

QString* Forge::Bearer::get_access_token() const
{
	return m_access_token;
}

void Forge::Bearer::set_access_token(QString* const access_token)
{
	this->m_access_token = access_token;
}

QString* Forge::Bearer::get_refresh_token() const
{
	return m_refresh_token;
}

void Forge::Bearer::set_refresh_token(QString* const refresh_token)
{
	this->m_refresh_token = refresh_token;
}

Forge::TOKEN_CONTEXT Forge::Bearer::get_token_context() const
{
	return m_token_context;
}

void Forge::Bearer::set_token_context(const TOKEN_CONTEXT token_context)
{
	m_token_context = token_context;
}



