#pragma once

#include "Message.h"
#include <Structs/GameId.h>
#include <Buffer.hpp>
#include <Stl.hpp>

using TiltedPhoques::String;
using TiltedPhoques::Map;

struct EnterCellRequest final : ClientMessage
{
    EnterCellRequest()
        : ClientMessage(kEnterCellRequest)
    {
    }

    void SerializeRaw(TiltedPhoques::Buffer::Writer& aWriter) const noexcept override;
    void DeserializeRaw(TiltedPhoques::Buffer::Reader& aReader) noexcept override;

    bool operator==(const EnterCellRequest& acRhs) const noexcept
    {
        return CellId == acRhs.CellId &&
            GetOpcode() == acRhs.GetOpcode();
    }
    
    GameId CellId{};
};
