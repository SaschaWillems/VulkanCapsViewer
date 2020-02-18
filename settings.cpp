#include "settings.h"
#include "QNetworkProxy"

settings::settings()
{
}


settings::~settings()
{
}

void settings::restore()
{
	QSettings settings("saschawillems", "glcapsviewer");
	submitterName = settings.value("global/submitterName", "").toString();
	proxyDns = settings.value("proxy/dns", "").toString();
	proxyPort = settings.value("proxy/port", "").toString();
	proxyUserName = settings.value("proxy/user", "").toString();
	proxyUserPassword = settings.value("proxy/password", "").toString();
	proxyEnabled = settings.value("proxy/enabled", "").toBool();

	// Apply proxy settings
	if (proxyEnabled) {
		QNetworkProxy proxy;
		proxy.setType(QNetworkProxy::Socks5Proxy);
		proxy.setHostName(proxyDns);
		if (!proxyPort.isEmpty()) {
			proxy.setPort(proxyPort.toInt());
		}
		else {
			proxy.setPort(80);
		}
		proxy.setUser(proxyUserName);
		proxy.setPassword(proxyUserPassword);
		QNetworkProxy::setApplicationProxy(proxy);
	}
	else {
		QNetworkProxy::setApplicationProxy(QNetworkProxy::NoProxy);
	}

}
