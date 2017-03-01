#pragma once

#include "baseapi.h"
#include "httprequest.h"

namespace Forge {
class TwoLeggedApi : public BaseApi
{
	Q_OBJECT

public:
	
	TwoLeggedApi(QObject *parent = nullptr);
	~TwoLeggedApi();


	void getTokenWithScope(QString scope) override;
	void set_client_id(const QString& client_id);
	void set_client_secret(const QString& client_secret);
	QString get_client_id() const;
	QString get_client_secret() const;

signals:
	void authenticateSignal(Bearer* summary);


private:
	void authenticationCallback(HttpRequestWorker* worker);
	QString m_client_id;
	QString m_client_secret;


};
}
