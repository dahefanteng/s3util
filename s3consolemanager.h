#ifndef S3CONSOLEMANAGER_H
#define S3CONSOLEMANAGER_H

#include <QObject>
#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <qs3client.h>

using namespace qlibs3;

class S3ConsoleManager : public QObject
{
    Q_OBJECT
public:
    void ListObjects(const QString &bucketName, const QString &marker, const QString &prefix);
    void PutObject(const QString &srcPath, const QString &bucketName, const QString &objectName);
    void GetObject(const QString &bucketName, const QString &objectName, const QString &dstPath);
    void CreateBucket(const QString &bucketName);
    void DeleteBucket(const QString &bucketName);
    void DeleteObject(const QString &bucketName,const QString &objectName);
    void ListBuckets();

    explicit S3ConsoleManager(QObject *parent = 0);
    ~S3ConsoleManager();
    QStringList args;

signals:
    void Finished();

public slots:
    void Execute();

    void DeleteOneFile();
    void ListBucketInfo(s3bucket  bucket);
    void Result(bool, s3error error);

    void ListObjectInfo(s3object);
    void ListPrefixInfo(s3prefix);
    void ListObjectResult(bool success, s3error error, bool truncated);

    void stop();

    void myProgress(uint64_t, uint64_t);
    void downloadOrUploadresult(TransferStatus);
    void progressError(s3error error);


    void showLog(const QString &log);
private:
    QS3Client *s3;
    ObjectHandlerInterface *h;
};

#endif // S3CONSOLEMANAGER_H
