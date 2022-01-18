#pragma once
#include <windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <cstdint>
#include <vector>
#include <string>

namespace t2k{

    const float PI = 3.14159265358979f;

	#define safeDelete( p ){ if(p){ delete p ; p = nullptr ; } }
	inline int ARGB8( int a, int r, int g, int b ) { return ( a << 24 | r << 16 | g << 8 | b ); }
	inline int RGBA8( int r, int g, int b, int a = 255 ) { return ( r << 24 | g << 16 | b << 8 | a ); }
	inline int ABGR8(int a, int b, int g, int r) { return (a << 24 | b << 16 | g << 8 | r); }

	//----------------------------------------------------------------------------------------------
	// index �t�� for( auto n : xxx )
	// ���p�@
	// std::list<int> xxx ;
	// for_with_index( it, xxx, i, 0, ++, ){
	// }
	#define for_with_index( it, data, idx, start_idx, fluct ) for( auto[it, idx] = std::pair{ (data).begin(), (start_idx) }; (it) != (data).end(); (it)++, (idx)fluct )

	//----------------------------------------------------------------------------------------------
	// CSV Loader
	std::vector<std::vector<std::string>> loadCsv( const std::string& file_name );

	//----------------------------------------------------------------------------------------------
	// ���W�A������f�O���[�ւ̕ϊ�
	inline float toDegree(float radian) {
		return (radian / PI * 180.0f );
	}

	//----------------------------------------------------------------------------------------------
	// �f�O���[���烉�W�A���ւ̕ϊ�
	inline float toRadian(float degree) {
		return (PI / 180.0f * degree );
	}

	//----------------------------------------------------------------------------------------------
	// �f�o�b�O�R���\�[���ւ̏o��
	inline void debugTrace(const char* _str, ...) {
    #if _DEBUG
		char buff[255] = { 0 };
		va_list argptr;
		va_start(argptr, _str);
		vsprintf_s(buff, _str, argptr);
		va_end(argptr);
		OutputDebugString(buff);
    #endif
	}

	//----------------------------------------------------------------------------------------------
	// �x���o��
    #define warningMassage( m ){                            \
        t2k::debugTrace("\n������������������������������\n") ;      \
        t2k::debugTrace( m ) ; t2k::debugTrace("\n") ;                \
        t2k::debugTrace("%s", __FILE__) ; t2k::debugTrace("\n") ;         \
        t2k::debugTrace("�s�ԍ� : %d", __LINE__) ; t2k::debugTrace("\n") ;\
        t2k::debugTrace("\n��������������������������������\n\n") ;    \
    }

	//----------------------------------------------------------------------------------------------
	// ���ʃr�b�g 0 ���� �w�茅�̃r�b�g���L���Ȑ��l�����
	inline int onBit(int n) { return (1 << n); }

	//----------------------------------------------------------------------------------------------
	// �P�r�b�g�ÂԊu���J����
	int spaceBit32(int n);

	//----------------------------------------------------------------------------------------------
	// �L���ȃr�b�g���J�E���g����
	int countBit8(const uint8_t v);
	int countBit16(const uint16_t v);
	int countBit32(const uint32_t v);
	int countBit64(const uint64_t v);

	//----------------------------------------------------------------------------------------------
	// �ő�L���r�b�g���iMSB�FMost Significant Bit�j
	// �S�Ẵr�b�g�� 0 �Ȃ� false ���A��
	// ��) value �� 0xFF �Ȃ� out �ɂ� value �� Bit��-1 ������ uint8_t �Ȃ� 7
	bool mostBit8(const uint8_t value, int& out);
	bool mostBit16(const uint16_t value, int& out);
	bool mostBit32(const uint32_t value, int& out);
	bool mostBit64(const uint64_t value, int& out);

	//----------------------------------------------------------------------------------------------
	// �ŏ��L���r�b�g���iLSB�FLeast Significant Bit�j
	// �S�Ẵr�b�g�� 0 �Ȃ� false ���A��
	// ��) value �� 0x01 �Ȃ� out �ɂ� 0 ������
	bool leastBit8(const uint8_t value, int& out);
	bool leastBit16(const uint16_t value, int& out);
	bool leastBit32(const uint32_t value, int& out);
	bool leastBit64(const uint64_t value, int& out);

}