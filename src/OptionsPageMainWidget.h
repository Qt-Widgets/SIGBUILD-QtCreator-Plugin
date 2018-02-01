#pragma once

#include <QWidget>

class QCheckBox;
class QSpinBox;

namespace QtCreatorSysTray
{

class Settings;

class OptionsPageMainWidget : public QWidget
{
	Q_OBJECT

public:
	explicit OptionsPageMainWidget(const Settings * settings);

	Settings GenerateSettings() const;

private:
	// -- SYSTRAY BOX --
	QCheckBox * mSystrayEnabled = nullptr;
	QCheckBox * mSystrayNotifyEnabled = nullptr;
	QCheckBox * mSystrayNotifyWhenActive = nullptr;
	QSpinBox * mSystrayMinBuildTime = nullptr;

	// -- AUDIO BOX --
	QCheckBox * mAudioEnabled = nullptr;
	QCheckBox * mAudioNotifyWhenActive = nullptr;
	QSpinBox * mAudioVolume = nullptr;
	QSpinBox * mAudioMinBuildTime = nullptr;
};

} // namespace QtCreatorSysTray
