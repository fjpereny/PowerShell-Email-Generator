/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../PowerShell-Email-Generator/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[72];
    char stringdata0[657];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(35, 0), // ""
QT_MOC_LITERAL(36, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(60, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(85, 45), // "on_actionGenerate_PowerShell_..."
QT_MOC_LITERAL(131, 10), // "create_XML"
QT_MOC_LITERAL(142, 22), // "tinyxml2::XMLDocument*"
QT_MOC_LITERAL(165, 28), // "on_projectNameButton_clicked"
QT_MOC_LITERAL(194, 28), // "on_projectGateButton_clicked"
QT_MOC_LITERAL(223, 24), // "on_gateDueButton_clicked"
QT_MOC_LITERAL(248, 21), // "on_taskButton_clicked"
QT_MOC_LITERAL(270, 22), // "on_ownerButton_clicked"
QT_MOC_LITERAL(293, 27), // "on_ownerEmailButton_clicked"
QT_MOC_LITERAL(321, 24), // "on_managerButton_clicked"
QT_MOC_LITERAL(346, 29), // "on_managerEmailButton_clicked"
QT_MOC_LITERAL(376, 23), // "on_statusButton_clicked"
QT_MOC_LITERAL(400, 24), // "on_dueDateButton_clicked"
QT_MOC_LITERAL(425, 25), // "on_generateButton_clicked"
QT_MOC_LITERAL(451, 20), // "create_script_header"
QT_MOC_LITERAL(472, 16), // "createMailScript"
QT_MOC_LITERAL(489, 2), // "to"
QT_MOC_LITERAL(492, 2), // "cc"
QT_MOC_LITERAL(495, 3), // "bcc"
QT_MOC_LITERAL(499, 7), // "subject"
QT_MOC_LITERAL(507, 4), // "body"
QT_MOC_LITERAL(512, 11), // "attachments"
QT_MOC_LITERAL(524, 15), // "generate_script"
QT_MOC_LITERAL(540, 33), // "on_tableWidget_currentCellCha..."
QT_MOC_LITERAL(574, 10), // "currentRow"
QT_MOC_LITERAL(585, 13), // "currentColumn"
QT_MOC_LITERAL(599, 11), // "previousRow"
QT_MOC_LITERAL(611, 14), // "previousColumn"
QT_MOC_LITERAL(626, 13), // "keyPressEvent"
QT_MOC_LITERAL(640, 10), // "QKeyEvent*"
QT_MOC_LITERAL(651, 5) // "event"

    },
    "MainWindow\0on_actionOpen_triggered\0\0"
    "on_actionSave_triggered\0"
    "on_actionClose_triggered\0"
    "on_actionGenerate_PowerShell_Script_triggered\0"
    "create_XML\0tinyxml2::XMLDocument*\0"
    "on_projectNameButton_clicked\0"
    "on_projectGateButton_clicked\0"
    "on_gateDueButton_clicked\0on_taskButton_clicked\0"
    "on_ownerButton_clicked\0"
    "on_ownerEmailButton_clicked\0"
    "on_managerButton_clicked\0"
    "on_managerEmailButton_clicked\0"
    "on_statusButton_clicked\0"
    "on_dueDateButton_clicked\0"
    "on_generateButton_clicked\0"
    "create_script_header\0createMailScript\0"
    "to\0cc\0bcc\0subject\0body\0attachments\0"
    "generate_script\0on_tableWidget_currentCellChanged\0"
    "currentRow\0currentColumn\0previousRow\0"
    "previousColumn\0keyPressEvent\0QKeyEvent*\0"
    "event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  176,    2, 0x08,    1 /* Private */,
       3,    0,  177,    2, 0x08,    2 /* Private */,
       4,    0,  178,    2, 0x08,    3 /* Private */,
       5,    0,  179,    2, 0x08,    4 /* Private */,
       6,    0,  180,    2, 0x08,    5 /* Private */,
       8,    0,  181,    2, 0x08,    6 /* Private */,
       9,    0,  182,    2, 0x08,    7 /* Private */,
      10,    0,  183,    2, 0x08,    8 /* Private */,
      11,    0,  184,    2, 0x08,    9 /* Private */,
      12,    0,  185,    2, 0x08,   10 /* Private */,
      13,    0,  186,    2, 0x08,   11 /* Private */,
      14,    0,  187,    2, 0x08,   12 /* Private */,
      15,    0,  188,    2, 0x08,   13 /* Private */,
      16,    0,  189,    2, 0x08,   14 /* Private */,
      17,    0,  190,    2, 0x08,   15 /* Private */,
      18,    0,  191,    2, 0x08,   16 /* Private */,
      19,    0,  192,    2, 0x08,   17 /* Private */,
      20,    6,  193,    2, 0x08,   18 /* Private */,
      20,    5,  206,    2, 0x28,   25 /* Private | MethodCloned */,
      20,    4,  217,    2, 0x28,   31 /* Private | MethodCloned */,
      20,    3,  226,    2, 0x28,   36 /* Private | MethodCloned */,
      20,    2,  233,    2, 0x28,   40 /* Private | MethodCloned */,
      20,    1,  238,    2, 0x28,   43 /* Private | MethodCloned */,
      20,    0,  241,    2, 0x28,   45 /* Private | MethodCloned */,
      27,    0,  242,    2, 0x08,   46 /* Private */,
      28,    4,  243,    2, 0x08,   47 /* Private */,
      33,    1,  252,    2, 0x08,   52 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   21,   22,   23,   24,   25,   26,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   21,   22,   23,   24,   25,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   21,   22,   23,   24,
    QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   21,   22,   23,
    QMetaType::QString, QMetaType::QString, QMetaType::QString,   21,   22,
    QMetaType::QString, QMetaType::QString,   21,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   29,   30,   31,   32,
    QMetaType::Void, 0x80000000 | 34,   35,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionOpen_triggered(); break;
        case 1: { bool _r = _t->on_actionSave_triggered();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->on_actionClose_triggered(); break;
        case 3: _t->on_actionGenerate_PowerShell_Script_triggered(); break;
        case 4: { tinyxml2::XMLDocument* _r = _t->create_XML();
            if (_a[0]) *reinterpret_cast< tinyxml2::XMLDocument**>(_a[0]) = std::move(_r); }  break;
        case 5: _t->on_projectNameButton_clicked(); break;
        case 6: _t->on_projectGateButton_clicked(); break;
        case 7: _t->on_gateDueButton_clicked(); break;
        case 8: _t->on_taskButton_clicked(); break;
        case 9: _t->on_ownerButton_clicked(); break;
        case 10: _t->on_ownerEmailButton_clicked(); break;
        case 11: _t->on_managerButton_clicked(); break;
        case 12: _t->on_managerEmailButton_clicked(); break;
        case 13: _t->on_statusButton_clicked(); break;
        case 14: _t->on_dueDateButton_clicked(); break;
        case 15: _t->on_generateButton_clicked(); break;
        case 16: { QString _r = _t->create_script_header();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 17: { QString _r = _t->createMailScript((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 18: { QString _r = _t->createMailScript((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 19: { QString _r = _t->createMailScript((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 20: { QString _r = _t->createMailScript((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 21: { QString _r = _t->createMailScript((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 22: { QString _r = _t->createMailScript((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 23: { QString _r = _t->createMailScript();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 24: _t->generate_script(); break;
        case 25: _t->on_tableWidget_currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 26: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<tinyxml2::XMLDocument *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QKeyEvent *, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 27;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
