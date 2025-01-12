// Copyright (C) 2022 Jérôme "Lynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Utility library"
// For conditions of distribution and use, see copyright notice in Config.hpp

#pragma once

#ifndef NAZARA_UTILS_CALLONEXIT_HPP
#define NAZARA_UTILS_CALLONEXIT_HPP

#include <Nazara/Prerequisites.hpp>
#include <optional>

namespace Nz
{
	template<typename F>
	class CallOnExit
	{
		public:
			CallOnExit() = default;
			CallOnExit(F&& functor);
			CallOnExit(const CallOnExit&) = delete;
			CallOnExit(CallOnExit&&) = delete;
			~CallOnExit();

			void CallAndReset();
			void Reset();

			CallOnExit& operator=(const CallOnExit&) = delete;
			CallOnExit& operator=(CallOnExit&&) = default;

		private:
			std::optional<F> m_functor;
	};

	template<typename F>
	CallOnExit(F) -> CallOnExit<F>;
}

#include <Nazara/Utils/CallOnExit.inl>

#endif // NAZARA_UTILS_CALLONEXIT_HPP
