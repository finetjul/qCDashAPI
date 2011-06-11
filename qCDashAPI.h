/*==============================================================================

  Program: 3D Slicer

  Copyright (c) 2010 Kitware Inc.

  See Doc/copyright/copyright.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

#ifndef __qCDashAPI_h
#define __qCDashAPI_h

// Qt includes
#include <QObject>

class qCDashAPIPrivate;

template <class Key, class T> class QHash;
typedef QHash<QString, QVariant> QVariantHash;

class qCDashAPI : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QString url READ url WRITE setUrl)
public:
  typedef QObject Superclass;
  explicit qCDashAPI(QObject*parent = 0);
  virtual ~qCDashAPI();

  enum LogLevel
    {
    SILENT = 0,
    LOW,
    HIGH
    };

  QString url()const;
  void setUrl(const QString& newUrl);

  LogLevel logLevel()const;
  void setLogLevel(LogLevel level);

  void queryProjectFiles(const QString& project, const QString& match = QString());
  void queryProjectList();

signals:
  void projectFilesReceived(const QList<QVariantHash>&);
  void projectListReceived(const QList<QVariantHash>&);

protected:
  QScopedPointer<qCDashAPIPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(qCDashAPI);
  Q_DISABLE_COPY(qCDashAPI);
};

#endif

