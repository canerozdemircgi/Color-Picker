#pragma once

#include <QtCore/QString>

#include <concepts>

template <typename T>
concept CString = std::same_as<T, QString> || std::same_as<T, QByteArray>;