#pragma once

#include "GazeHidUsages.h"

using namespace Windows::Devices::HumanInterfaceDevice;
using namespace Windows::Devices::Input::Preview;

BEGIN_NAMESPACE_GAZE_INPUT

namespace GazeHidParsers {
    public ref class GazeHidPosition sealed
    {
    public:
        property long long X;
        property long long Y;
        property long long Z;
    };

    public ref class GazeHidPositionParser sealed
    {
    public:
        GazeHidPositionParser(GazeDevicePreview ^ gazeDevice, uint16 usage);

        GazeHidPosition^ GetPosition(HidInputReport ^ report);

    private:
        HidNumericControlDescription ^ _X = nullptr;
        HidNumericControlDescription ^ _Y = nullptr;
        HidNumericControlDescription ^ _Z = nullptr;
        uint16 _usage                     = 0x0000;
    };

    public ref class GazeHidRotationParser sealed
    {
    public:
        GazeHidRotationParser(GazeDevicePreview ^ gazeDevice, uint16 usage);

        GazeHidPosition^ GetRotation(HidInputReport^ report);

    private:
        HidNumericControlDescription ^ _X = nullptr;
        HidNumericControlDescription ^ _Y = nullptr;
        HidNumericControlDescription ^ _Z = nullptr;
        uint16 _usage                     = 0x0000;
    };

    public ref class LeftEyePositionParser sealed
    {
    public:
        LeftEyePositionParser(GazeDevicePreview ^ gazeDevice) { _gazeHidPositionParser = ref new GazeHidPositionParser(gazeDevice, (USHORT)GazeHidUsages::Usage_LeftEyePosition); }

        GazeHidPosition^ GetPosition(HidInputReport ^ report) { return _gazeHidPositionParser->GetPosition(report); }
    private:
        GazeHidPositionParser ^ _gazeHidPositionParser;
    };

    public ref class RightEyePositionParser sealed
    {
    public:
        RightEyePositionParser(GazeDevicePreview ^ gazeDevice) { _gazeHidPositionParser = ref new GazeHidPositionParser(gazeDevice, (USHORT)GazeHidUsages::Usage_RightEyePosition); }

        GazeHidPosition^ GetPosition(HidInputReport ^ report) { return _gazeHidPositionParser->GetPosition(report); }
    private:
        GazeHidPositionParser ^ _gazeHidPositionParser;
    };

    public ref class HeadPositionParser sealed
    {
    public:
        HeadPositionParser(GazeDevicePreview ^ gazeDevice) { _gazeHidPositionParser = ref new GazeHidPositionParser(gazeDevice, (USHORT)GazeHidUsages::Usage_HeadPosition); }

        GazeHidPosition^ GetPosition(HidInputReport ^ report) { return _gazeHidPositionParser->GetPosition(report); }
    private:
        GazeHidPositionParser ^ _gazeHidPositionParser;
    };

    public ref class HeadRotationParser sealed
    {
    public:
        HeadRotationParser(GazeDevicePreview ^ gazeDevice) { _gazeHidRotationParser = ref new GazeHidRotationParser(gazeDevice, (USHORT)GazeHidUsages::Usage_HeadDirectionPoint); }

        GazeHidPosition^ GetRotation(HidInputReport ^ report) { return _gazeHidRotationParser->GetRotation(report); }
    private:
        GazeHidRotationParser ^ _gazeHidRotationParser;
    };
}

END_NAMESPACE_GAZE_INPUT
