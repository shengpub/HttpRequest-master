#pragma once
#include <windows.h>
#include <string>
#include "httpRequestDef.h"
#include "HttpRequest_global.h"

// class HttpReply - Http��Ӧ��
class HTTP_REQUEST_EXPORT HttpReply
{
public:
	explicit HttpReply(int requestId = 0);
	~HttpReply();

	int id() const { return m_id; }
	long httpStatusCode() const { return m_http_code; }
	std::string readAll() const { return m_receive_content; }
	std::string header() const { return m_receive_header; }
	std::string errorString() const {return m_error_string;}

private:
	void setRequestType(HttpRequestType type);
	void setResultCallback(ResultCallback rc);
	void setProgressCallback(ProgressCallback pc);

	friend class CURLWrapper;

public:
	void replyProgress(int id, bool is_download, INT64 total_size, INT64 current_size);
	void replyResult(bool bSuccess);

private:
	ResultCallback  m_result_callback;
	ProgressCallback  m_progress_callback;

	//����ֵ
	long m_http_code;
	std::string	m_receive_header;
	std::string	m_receive_content;
	std::string	m_error_string;
	int m_id;
	HttpRequestType m_type;
};
