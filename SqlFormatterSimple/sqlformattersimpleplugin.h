#ifndef SQLFORMATTERSIMPLEPLUGIN_H
#define SQLFORMATTERSIMPLEPLUGIN_H

#include "sqlformattersimple_global.h"
#include "sqlformatterplugin.h"
#include "cfginternals.h"
#include "genericplugin.h"
#include <QObject>

CFG_CATEGORIES(SqlFormatterSimpleConfig,
     CFG_CATEGORY(SqlFormatterSimple,
         CFG_ENTRY(bool, UpperCaseKeywords, "upperCaseKeywords", true)
         CFG_ENTRY(bool, TrimLongSpaces,    "trimLongSpaces", true)
     )
)

CFG_DECLARE(SqlFormatterSimpleConfig)
#define SIMPLE_FMT_CFG CFG_INSTANCE(SqlFormatterSimpleConfig)

class SQLFORMATTERSIMPLESHARED_EXPORT SqlFormatterSimplePlugin : public GenericPlugin, public SqlFormatterPlugin
{
        Q_OBJECT

        SQLITESTUDIO_PLUGIN
        SQLITESTUDIO_PLUGIN_TITLE("Simple")
        SQLITESTUDIO_PLUGIN_DESC("Basic formatter with very little options.")
        SQLITESTUDIO_PLUGIN_VERSION(10000)
        SQLITESTUDIO_PLUGIN_AUTHOR("sqlitestudio.pl")
        SQLITESTUDIO_PLUGIN_UI("SqlFormatterSimplePlugin")

    public:
        SqlFormatterSimplePlugin();

        QString format(SqliteQueryPtr query);
        QString getConfigTitle() const;
};

#endif // SQLFORMATTERSIMPLEPLUGIN_H