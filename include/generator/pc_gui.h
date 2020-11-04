//
// Created by Ahmed Abou Aliaa on 04.11.20.
//

#ifndef ALIFC_PC_GUI_H
#define ALIFC_PC_GUI_H
#include <string>

void cpp_AddScript(std::string FUN, std::string NEW_CODE);
std::string CG_WINX_LOAD();
std::string CG_APP_DESTROY();
std::string CG_WIN_SHOW(std::string WIN);
std::string CG_WIN_CENTER(std::string WIN);
std::string CG_WIN_HIDE(std::string WIN);
std::string CG_WIN_DESTROY(std::string WIN);
std::string CG_WIN_MEMBER(std::string WIN, std::string MEMBER_CODE);
std::string AlifJavaScript_Bridge_SendRequest();
std::string AlifJavaScript_Bridge_OnNewWindowSendRequest(std::string WVObjName);
std::string Generate_AlifJavaScript();
void CG_INITIALIZATION();
std::string CG_WINX_CODE();
std::string CODE_GENERATOR_GET_PC_GUI();

std::string AlifJavaScript_Bridge = R"V0G0N(
<script>
	// *** AlifJS Bridge ***

	var AlifJSBridg_Res = '';
	var AlifJSBridg_Status = false;

	function Alif(/**/){

		var args = arguments;
		var link = '';

		for(var i=0; i < args.length; i++){
			if(typeof args[i] === 'object'){
				alert('[جسر ألف]\n\n' +
					'معطيات رقم ' + i + ' من نوع كائن');
				return '';
			}
			link = link + '~@' + args[i];
		}

		)V0G0N" + AlifJavaScript_Bridge_SendRequest() +
                                    R"V0G0N(

		if(!AlifJSBridg_Status && AlifJSBridg_Res != ''){

			alert('[جسر ألف]\n\n' + AlifJSBridg_Res);
			return '';

		} else {

			var Res = AlifJSBridg_Res;
			AlifJSBridg_Res = '';
			AlifJSBridg_Status = false;
			return Res;
		}
	}
</script>
</html>
)V0G0N";

#endif // ALIFC_PC_GUI_H
