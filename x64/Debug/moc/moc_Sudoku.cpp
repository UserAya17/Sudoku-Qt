/****************************************************************************
** Meta object code from reading C++ file 'Sudoku.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Sudoku.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Sudoku.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSudokuENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSudokuENDCLASS = QtMocHelpers::stringData(
    "Sudoku",
    "on_Stopped",
    "",
    "on_Clear_clicked",
    "on_SolveSlow_clicked",
    "on_Solve_clicked",
    "on_Undo_Solve_clicked",
    "on_Stop_Recussion_clicked",
    "DisplaySingleItem",
    "i",
    "j",
    "n",
    "initializeGrid",
    "resetToInitial",
    "on_RandomV_clicked",
    "on_CntrlzButton_clicked",
    "popMove",
    "pushMove",
    "x",
    "y",
    "value",
    "onCurrentItemChanged",
    "QTableWidgetItem*",
    "current",
    "previous",
    "onCellChanged",
    "row",
    "col"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSudokuENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,  105,    2, 0x08,    2 /* Private */,
       4,    0,  106,    2, 0x08,    3 /* Private */,
       5,    0,  107,    2, 0x08,    4 /* Private */,
       6,    0,  108,    2, 0x08,    5 /* Private */,
       7,    0,  109,    2, 0x08,    6 /* Private */,
       8,    3,  110,    2, 0x0a,    7 /* Public */,
      12,    0,  117,    2, 0x0a,   11 /* Public */,
      13,    0,  118,    2, 0x0a,   12 /* Public */,
      14,    0,  119,    2, 0x0a,   13 /* Public */,
      15,    0,  120,    2, 0x0a,   14 /* Public */,
      16,    0,  121,    2, 0x0a,   15 /* Public */,
      17,    3,  122,    2, 0x0a,   16 /* Public */,
      21,    2,  129,    2, 0x0a,   20 /* Public */,
      25,    2,  134,    2, 0x0a,   23 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   18,   19,   20,
    QMetaType::Void, 0x80000000 | 22, 0x80000000 | 22,   23,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   26,   27,

       0        // eod
};

Q_CONSTINIT const QMetaObject Sudoku::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSSudokuENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSudokuENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSudokuENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Sudoku, std::true_type>,
        // method 'on_Stopped'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Clear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_SolveSlow_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Solve_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Undo_Solve_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_Stop_Recussion_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'DisplaySingleItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'initializeGrid'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'resetToInitial'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_RandomV_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_CntrlzButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'popMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pushMove'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onCurrentItemChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>,
        // method 'onCellChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void Sudoku::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Sudoku *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_Stopped(); break;
        case 1: _t->on_Clear_clicked(); break;
        case 2: _t->on_SolveSlow_clicked(); break;
        case 3: _t->on_Solve_clicked(); break;
        case 4: _t->on_Undo_Solve_clicked(); break;
        case 5: _t->on_Stop_Recussion_clicked(); break;
        case 6: _t->DisplaySingleItem((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->initializeGrid(); break;
        case 8: _t->resetToInitial(); break;
        case 9: _t->on_RandomV_clicked(); break;
        case 10: _t->on_CntrlzButton_clicked(); break;
        case 11: _t->popMove(); break;
        case 12: _t->pushMove((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 13: _t->onCurrentItemChanged((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[2]))); break;
        case 14: _t->onCellChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Sudoku::*)();
            if (_t _q_method = &Sudoku::on_Stopped; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *Sudoku::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sudoku::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSudokuENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Sudoku::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Sudoku::on_Stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
