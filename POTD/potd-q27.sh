#!/bin/sh
# This script was generated using Makeself 2.3.0

ORIG_UMASK=`umask`
if test "n" = n; then
    umask 077
fi

CRCsum="136016668"
MD5="e44691011da04371f82584a59e004d09"
TMPROOT=${TMPDIR:=/tmp}
USER_PWD="$PWD"; export USER_PWD

label="Extracting potd-q27"
script="echo"
scriptargs="The initial files can be found in the newly created directory: potd-q27"
licensetxt=""
helpheader=''
targetdir="potd-q27"
filesizes="10381"
keep="y"
nooverwrite="n"
quiet="n"
nodiskspace="n"

print_cmd_arg=""
if type printf > /dev/null; then
    print_cmd="printf"
elif test -x /usr/ucb/echo; then
    print_cmd="/usr/ucb/echo"
else
    print_cmd="echo"
fi

unset CDPATH

MS_Printf()
{
    $print_cmd $print_cmd_arg "$1"
}

MS_PrintLicense()
{
  if test x"$licensetxt" != x; then
    echo "$licensetxt"
    while true
    do
      MS_Printf "Please type y to accept, n otherwise: "
      read yn
      if test x"$yn" = xn; then
        keep=n
	eval $finish; exit 1
        break;
      elif test x"$yn" = xy; then
        break;
      fi
    done
  fi
}

MS_diskspace()
{
	(
	if test -d /usr/xpg4/bin; then
		PATH=/usr/xpg4/bin:$PATH
	fi
	df -kP "$1" | tail -1 | awk '{ if ($4 ~ /%/) {print $3} else {print $4} }'
	)
}

MS_dd()
{
    blocks=`expr $3 / 1024`
    bytes=`expr $3 % 1024`
    dd if="$1" ibs=$2 skip=1 obs=1024 conv=sync 2> /dev/null | \
    { test $blocks -gt 0 && dd ibs=1024 obs=1024 count=$blocks ; \
      test $bytes  -gt 0 && dd ibs=1 obs=1024 count=$bytes ; } 2> /dev/null
}

MS_dd_Progress()
{
    if test x"$noprogress" = xy; then
        MS_dd $@
        return $?
    fi
    file="$1"
    offset=$2
    length=$3
    pos=0
    bsize=4194304
    while test $bsize -gt $length; do
        bsize=`expr $bsize / 4`
    done
    blocks=`expr $length / $bsize`
    bytes=`expr $length % $bsize`
    (
        dd ibs=$offset skip=1 2>/dev/null
        pos=`expr $pos \+ $bsize`
        MS_Printf "     0%% " 1>&2
        if test $blocks -gt 0; then
            while test $pos -le $length; do
                dd bs=$bsize count=1 2>/dev/null
                pcent=`expr $length / 100`
                pcent=`expr $pos / $pcent`
                if test $pcent -lt 100; then
                    MS_Printf "\b\b\b\b\b\b\b" 1>&2
                    if test $pcent -lt 10; then
                        MS_Printf "    $pcent%% " 1>&2
                    else
                        MS_Printf "   $pcent%% " 1>&2
                    fi
                fi
                pos=`expr $pos \+ $bsize`
            done
        fi
        if test $bytes -gt 0; then
            dd bs=$bytes count=1 2>/dev/null
        fi
        MS_Printf "\b\b\b\b\b\b\b" 1>&2
        MS_Printf " 100%%  " 1>&2
    ) < "$file"
}

MS_Help()
{
    cat << EOH >&2
${helpheader}Makeself version 2.3.0
 1) Getting help or info about $0 :
  $0 --help   Print this message
  $0 --info   Print embedded info : title, default target directory, embedded script ...
  $0 --lsm    Print embedded lsm entry (or no LSM)
  $0 --list   Print the list of files in the archive
  $0 --check  Checks integrity of the archive

 2) Running $0 :
  $0 [options] [--] [additional arguments to embedded script]
  with following options (in that order)
  --confirm             Ask before running embedded script
  --quiet		Do not print anything except error messages
  --noexec              Do not run embedded script
  --keep                Do not erase target directory after running
			the embedded script
  --noprogress          Do not show the progress during the decompression
  --nox11               Do not spawn an xterm
  --nochown             Do not give the extracted files to the current user
  --nodiskspace         Do not check for available disk space
  --target dir          Extract directly to a target directory
                        directory path can be either absolute or relative
  --tar arg1 [arg2 ...] Access the contents of the archive through the tar command
  --                    Following arguments will be passed to the embedded script
EOH
}

MS_Check()
{
    OLD_PATH="$PATH"
    PATH=${GUESS_MD5_PATH:-"$OLD_PATH:/bin:/usr/bin:/sbin:/usr/local/ssl/bin:/usr/local/bin:/opt/openssl/bin"}
	MD5_ARG=""
    MD5_PATH=`exec <&- 2>&-; which md5sum || command -v md5sum || type md5sum`
    test -x "$MD5_PATH" || MD5_PATH=`exec <&- 2>&-; which md5 || command -v md5 || type md5`
	test -x "$MD5_PATH" || MD5_PATH=`exec <&- 2>&-; which digest || command -v digest || type digest`
    PATH="$OLD_PATH"

    if test x"$quiet" = xn; then
		MS_Printf "Verifying archive integrity..."
    fi
    offset=`head -n 532 "$1" | wc -c | tr -d " "`
    verb=$2
    i=1
    for s in $filesizes
    do
		crc=`echo $CRCsum | cut -d" " -f$i`
		if test -x "$MD5_PATH"; then
			if test x"`basename $MD5_PATH`" = xdigest; then
				MD5_ARG="-a md5"
			fi
			md5=`echo $MD5 | cut -d" " -f$i`
			if test x"$md5" = x00000000000000000000000000000000; then
				test x"$verb" = xy && echo " $1 does not contain an embedded MD5 checksum." >&2
			else
				md5sum=`MS_dd_Progress "$1" $offset $s | eval "$MD5_PATH $MD5_ARG" | cut -b-32`;
				if test x"$md5sum" != x"$md5"; then
					echo "Error in MD5 checksums: $md5sum is different from $md5" >&2
					exit 2
				else
					test x"$verb" = xy && MS_Printf " MD5 checksums are OK." >&2
				fi
				crc="0000000000"; verb=n
			fi
		fi
		if test x"$crc" = x0000000000; then
			test x"$verb" = xy && echo " $1 does not contain a CRC checksum." >&2
		else
			sum1=`MS_dd_Progress "$1" $offset $s | CMD_ENV=xpg4 cksum | awk '{print $1}'`
			if test x"$sum1" = x"$crc"; then
				test x"$verb" = xy && MS_Printf " CRC checksums are OK." >&2
			else
				echo "Error in checksums: $sum1 is different from $crc" >&2
				exit 2;
			fi
		fi
		i=`expr $i + 1`
		offset=`expr $offset + $s`
    done
    if test x"$quiet" = xn; then
		echo " All good."
    fi
}

UnTAR()
{
    if test x"$quiet" = xn; then
		tar $1vf - 2>&1 || { echo Extraction failed. > /dev/tty; kill -15 $$; }
    else

		tar $1f - 2>&1 || { echo Extraction failed. > /dev/tty; kill -15 $$; }
    fi
}

finish=true
xterm_loop=
noprogress=n
nox11=n
copy=none
ownership=y
verbose=n

initargs="$@"

while true
do
    case "$1" in
    -h | --help)
	MS_Help
	exit 0
	;;
    -q | --quiet)
	quiet=y
	noprogress=y
	shift
	;;
    --info)
	echo Identification: "$label"
	echo Target directory: "$targetdir"
	echo Uncompressed size: 96 KB
	echo Compression: gzip
	echo Date of packaging: Mon Mar  6 03:19:49 CST 2017
	echo Built with Makeself version 2.3.0 on linux-gnu
	echo Build command was: "makeself/makeself.sh \\
    \"--notemp\" \\
    \"../../questions/potd2_027_binaryTree_height/potd-q27\" \\
    \"potd-q27.sh\" \\
    \"Extracting potd-q27\" \\
    \"echo\" \\
    \"The initial files can be found in the newly created directory: potd-q27\""
	if test x"$script" != x; then
	    echo Script run after extraction:
	    echo "    " $script $scriptargs
	fi
	if test x"" = xcopy; then
		echo "Archive will copy itself to a temporary location"
	fi
	if test x"n" = xy; then
		echo "Root permissions required for extraction"
	fi
	if test x"y" = xy; then
	    echo "directory $targetdir is permanent"
	else
	    echo "$targetdir will be removed after extraction"
	fi
	exit 0
	;;
    --dumpconf)
	echo LABEL=\"$label\"
	echo SCRIPT=\"$script\"
	echo SCRIPTARGS=\"$scriptargs\"
	echo archdirname=\"potd-q27\"
	echo KEEP=y
	echo NOOVERWRITE=n
	echo COMPRESS=gzip
	echo filesizes=\"$filesizes\"
	echo CRCsum=\"$CRCsum\"
	echo MD5sum=\"$MD5\"
	echo OLDUSIZE=96
	echo OLDSKIP=533
	exit 0
	;;
    --lsm)
cat << EOLSM
No LSM.
EOLSM
	exit 0
	;;
    --list)
	echo Target directory: $targetdir
	offset=`head -n 532 "$0" | wc -c | tr -d " "`
	for s in $filesizes
	do
	    MS_dd "$0" $offset $s | eval "gzip -cd" | UnTAR t
	    offset=`expr $offset + $s`
	done
	exit 0
	;;
	--tar)
	offset=`head -n 532 "$0" | wc -c | tr -d " "`
	arg1="$2"
    if ! shift 2; then MS_Help; exit 1; fi
	for s in $filesizes
	do
	    MS_dd "$0" $offset $s | eval "gzip -cd" | tar "$arg1" - "$@"
	    offset=`expr $offset + $s`
	done
	exit 0
	;;
    --check)
	MS_Check "$0" y
	exit 0
	;;
    --confirm)
	verbose=y
	shift
	;;
	--noexec)
	script=""
	shift
	;;
    --keep)
	keep=y
	shift
	;;
    --target)
	keep=y
	targetdir=${2:-.}
    if ! shift 2; then MS_Help; exit 1; fi
	;;
    --noprogress)
	noprogress=y
	shift
	;;
    --nox11)
	nox11=y
	shift
	;;
    --nochown)
	ownership=n
	shift
	;;
    --nodiskspace)
	nodiskspace=y
	shift
	;;
    --xwin)
	if test "n" = n; then
		finish="echo Press Return to close this window...; read junk"
	fi
	xterm_loop=1
	shift
	;;
    --phase2)
	copy=phase2
	shift
	;;
    --)
	shift
	break ;;
    -*)
	echo Unrecognized flag : "$1" >&2
	MS_Help
	exit 1
	;;
    *)
	break ;;
    esac
done

if test x"$quiet" = xy -a x"$verbose" = xy; then
	echo Cannot be verbose and quiet at the same time. >&2
	exit 1
fi

if test x"n" = xy -a `id -u` -ne 0; then
	echo "Administrative privileges required for this archive (use su or sudo)" >&2
	exit 1	
fi

if test x"$copy" \!= xphase2; then
    MS_PrintLicense
fi

case "$copy" in
copy)
    tmpdir=$TMPROOT/makeself.$RANDOM.`date +"%y%m%d%H%M%S"`.$$
    mkdir "$tmpdir" || {
	echo "Could not create temporary directory $tmpdir" >&2
	exit 1
    }
    SCRIPT_COPY="$tmpdir/makeself"
    echo "Copying to a temporary location..." >&2
    cp "$0" "$SCRIPT_COPY"
    chmod +x "$SCRIPT_COPY"
    cd "$TMPROOT"
    exec "$SCRIPT_COPY" --phase2 -- $initargs
    ;;
phase2)
    finish="$finish ; rm -rf `dirname $0`"
    ;;
esac

if test x"$nox11" = xn; then
    if tty -s; then                 # Do we have a terminal?
	:
    else
        if test x"$DISPLAY" != x -a x"$xterm_loop" = x; then  # No, but do we have X?
            if xset q > /dev/null 2>&1; then # Check for valid DISPLAY variable
                GUESS_XTERMS="xterm gnome-terminal rxvt dtterm eterm Eterm xfce4-terminal lxterminal kvt konsole aterm terminology"
                for a in $GUESS_XTERMS; do
                    if type $a >/dev/null 2>&1; then
                        XTERM=$a
                        break
                    fi
                done
                chmod a+x $0 || echo Please add execution rights on $0
                if test `echo "$0" | cut -c1` = "/"; then # Spawn a terminal!
                    exec $XTERM -title "$label" -e "$0" --xwin "$initargs"
                else
                    exec $XTERM -title "$label" -e "./$0" --xwin "$initargs"
                fi
            fi
        fi
    fi
fi

if test x"$targetdir" = x.; then
    tmpdir="."
else
    if test x"$keep" = xy; then
	if test x"$nooverwrite" = xy && test -d "$targetdir"; then
            echo "Target directory $targetdir already exists, aborting." >&2
            exit 1
	fi
	if test x"$quiet" = xn; then
	    echo "Creating directory $targetdir" >&2
	fi
	tmpdir="$targetdir"
	dashp="-p"
    else
	tmpdir="$TMPROOT/selfgz$$$RANDOM"
	dashp=""
    fi
    mkdir $dashp $tmpdir || {
	echo 'Cannot create target directory' $tmpdir >&2
	echo 'You should try option --target dir' >&2
	eval $finish
	exit 1
    }
fi

location="`pwd`"
if test x"$SETUP_NOCHECK" != x1; then
    MS_Check "$0"
fi
offset=`head -n 532 "$0" | wc -c | tr -d " "`

if test x"$verbose" = xy; then
	MS_Printf "About to extract 96 KB in $tmpdir ... Proceed ? [Y/n] "
	read yn
	if test x"$yn" = xn; then
		eval $finish; exit 1
	fi
fi

if test x"$quiet" = xn; then
	MS_Printf "Uncompressing $label"
fi
res=3
if test x"$keep" = xn; then
    trap 'echo Signal caught, cleaning up >&2; cd $TMPROOT; /bin/rm -rf $tmpdir; eval $finish; exit 15' 1 2 3 15
fi

if test x"$nodiskspace" = xn; then
    leftspace=`MS_diskspace $tmpdir`
    if test -n "$leftspace"; then
        if test "$leftspace" -lt 96; then
            echo
            echo "Not enough space left in "`dirname $tmpdir`" ($leftspace KB) to decompress $0 (96 KB)" >&2
            echo "Use --nodiskspace option to skip this check and proceed anyway" >&2
            if test x"$keep" = xn; then
                echo "Consider setting TMPDIR to a directory with more free space."
            fi
            eval $finish; exit 1
        fi
    fi
fi

for s in $filesizes
do
    if MS_dd_Progress "$0" $offset $s | eval "gzip -cd" | ( cd "$tmpdir"; umask $ORIG_UMASK ; UnTAR xp ) 1>/dev/null; then
		if test x"$ownership" = xy; then
			(PATH=/usr/xpg4/bin:$PATH; cd "$tmpdir"; chown -R `id -u` .;  chgrp -R `id -g` .)
		fi
    else
		echo >&2
		echo "Unable to decompress $0" >&2
		eval $finish; exit 1
    fi
    offset=`expr $offset + $s`
done
if test x"$quiet" = xn; then
	echo
fi

cd "$tmpdir"
res=0
if test x"$script" != x; then
    if test x"$verbose" = x"y"; then
		MS_Printf "OK to execute: $script $scriptargs $* ? [Y/n] "
		read yn
		if test x"$yn" = x -o x"$yn" = xy -o x"$yn" = xY; then
			eval "\"$script\" $scriptargs \"\$@\""; res=$?;
		fi
    else
		eval "\"$script\" $scriptargs \"\$@\""; res=$?
    fi
    if test "$res" -ne 0; then
		test x"$verbose" = xy && echo "The program '$script' returned an error code ($res)" >&2
    fi
fi
if test x"$keep" = xn; then
    cd $TMPROOT
    /bin/rm -rf $tmpdir
fi
eval $finish; exit $res
� �)�X�]t\�y����ֻ����a˾~"�h�/=,#?֖lY6�M��ܬV+i�jWއ&ƸP@��\���I�@��C��i1�5��z����H�Ci�r ���3s��ݱ�ҽ�����?���ܙf�C���૱�y��^�7�<ކF��Oq�p�����4x	��ohDb=�W&�%E���.�I�?��]�9tS�/�\���p��7����@#.�z��H�d��%��;���7ū��P4�زfc7��	1��D:�w��X�c.�B����	��c��[�J�^^��3*ֆ��~�v�G���P,�GF�ɐ�c��jǺ�5��,.�sj-OpbW�c���u5��E��bj�ڄ����Mn�Mfl%�niNfw8�F5k�4b�[7���͎��A��O\��Hg�s�+�9��6(��G�ϟ����Z��c�ވ�M���r��BmJ,tdR�x�FRC�pDēw����锫�ov��6� ƽW�q��� f1�E��x�/��V�@2�? #~��4�R8�I��,l�P�D��,.li�u�#i��ii��{c+M�}2�o��~��?]���0����t&=+�_���������5����'��9�a�k.�%��yo�O�t���'(N��Y�a��,��]ݹ����J��{�o��~D���Jԭ�$��~Agїy�����k���<���{�������8�ޢ��+�ܲ.(�9a ������?��67;�2=�h�Y�cXF��JB����!�:�}V���Ѿ�s���?���<���<����Y�����A�*��V��Wy��o��sQ��6���}�݃N摂���$��B�|Z~�<�Ӯ�,9������Zf��\�GM[OX7�l��:ےK2N�b��X)QE�y+5�Za싉��TH�f�_���a�s79I� .�݌���l��� f�R�ʽF�uH *��Ա�&h!Ev
2�L� S3� 	��
���Q��3��ЊҺ��k�oX�o&�T��*Z�a������!�WB�R�5�C�{n�I�g���T�<BA�a������M��Ҥ�u�4��&M�����H���&-�4�j	M��Фu%M֬���4Y��&�M6�I��?�I��4��8M:����c4�<M�-���_Ф�M���7��V�{u^�J��+��s	�HMޭ��W�4	��I�6�t�i��tr�@�E,��:�&����
�꼬�ۺ�%�lې@�k	�+G��c�N�a��}���Lg*8/g�8F�&�ؔ�\a�y���M+�&.In�-�J���I�O��Ť`Iea^��!��w(�DOn�Mv̕����y#�E�Q�K�H'c��NYz1����p�:����=�����.:D)�ʫr��k��m��	��v�k�3R/�hX�h:G��;��\�����,�M���͹ԥg�Vs��ޠewi�5�՚�5�ܵoP�ޡeG\��Xtz�d_�
+�W����N�K��F�Ю	��
�Zv���I��дl��wj�[��Zv/���wK�<��zi~�	��&3���E\g���]%;�*�>��q��B6��
�h���^�����UP�ZRXZ��g��Hr�2~֒�|-]^6
�
ZE�c �j���rhT�h��W@�~��6�<���A@B��dV��:��lά�eEx�YV�Y�N�Ьd��^�	gKE��.k� cg�N�-w��f�����AHK����P{I ל�1�P�`©
q69I�|�E�qݙD�f�pg�,}!n�k/Q�B�������.,Yiv�ɭ,�#�X�u�^��]*/&�c|�Ӊ��Ժ� �Pb)�~�DP7�L���U� 3�az�t������K���4Y��bϷ�R�K��%%�$K�U��p�"�8��\6����-�Po	n��TcC�r���F,ӊI�rE �оBg,d���?̚�5H�ˤ�u�hO]8\7�� 5j��ށP�6�gF��&w}�ۭ��Z]x�r(5��M��E�~�$�B FnTG��u��W_�UqR�衯����z�G�rQ�����L�[�0K8���ȭ	��Ѱ4�H�� >K=�y�b�=�e��BIc�G���D\J'eN|\�6�ź36Z��8��5g�(���r�0�M�4!��I����p�N,!�Ky���fX�e=�[��.�ِ����U�c�%�͜"[���8j�aC;mV�i�3Sv�([�-l�䧃hQ���%��'茁_=�#�XC��M�t�UE��h<�F�㎓��xF
��R�����\�bD�%zB1i8��(�}9
�,�\wY�-8�h�gb1l��FdK��߇�dc��QL����P*݄i�	�(��#�!�d�ݓH��Q�HE�Fp�A���F��$Rd#9B�4";L|K��8�$K^,�3�T�?�%OM��G��e!%dS�	�Ȑ���ՠJ�9R,���]���� zI6�!@$�X�?Ȫ��F�q�loR�d�V��Z)K�k��: ���Rc�����z�t�	��p��h_�@��j���f>��u���\�B�
$���{)�+��!��<䎑s��Z�����@,���q��l�A�Ir+
��@�B��Tr�a�ʝ�&��yL뫧� ��+�f�9� [=���{��7��I�*ndo���c����뺗*������B���SfrQG/G�)�u"u���w�$#u#�>y�����j�ecO&�"}��J�{}���(�U$�#O�������5RW�zš#�[JF��"�M��Sc�p�W��$��I�N��BK;��M�d쉨0	��X+��7�O
��w�8�����f���	�ñ��;�g*z�r����m#5?��^����;�kA�o��~����\gL<��v�eQ�;ص��#��P$�W��UӮ��T��S�` 5
v��$7Ͷ��{p�3E:h�W��!�YH�C��t�	L7 �q�%P��ўL"�-�� ���-u���<�O�5?�lR���UkK��ik9X��k���� 8Z��(]�z�c�;>��hp��cpbF'e\���_uU���+��q�ꊫ���+���~ܸ[0�bF�m���e�]fE�<���k�&؄hˬ�6�B���t�h�m��6&�ra�ӏ��>2�7tlY��C�R��]28��@�b?��ϳo{���99G�i�d�15w��2����z�_������=v��y��[�.e���l��v!a�P���g��{N|�EsuO+��Y�wX��$�^R֤{f��m�=�`ˆt�'�eȍ]w�M�J&Cc�M����IF��;M#w818���ݓJA�m(�C�,H�@<.�	$S���D����Ig���r��{C��Z������w "R_�T��a�N`-�P�)�� M{C���G�|fG��
)��u!C�����D�}�B��/P_����Mx��s�8�{��έ�`�8�6�ٕ3$���i�[e����9�͐ӗ���c� �8��d%�[b�����J��G�����`�QO%��b����_8SN�^X�����~���= �}��=襹����������?���~��o���B��������29�~���U������L����I����n�f��y&���K9���Ѕ������������1�M@���h�y尿0�u�/3i����=-�?La���N��?P8޵����d����B?�z��˻�Y�joڪ�O�k�ʶN�s������9�XM{��V���s9x����|&���8x/��9�����Σb�[���_��K�n���kM|�bfx��������9�7)p��:�9���
��h|p5}zcv�����sS	i �%1W�Ht(������������;������*~��h�/`h?���*�1�k|/�\9Cme�ۀ������#g���s���C��{ ����m���
�b�!�ϰ����=�_e�g���{;�/��Wp�f�׼������� ���?��{ ���o�O�0���O�����2�ۀ?��nXrN2��_f����9��Y�x
>Y8��{�O�F�~��e~�2��i��L������U�+�od�+�������w��0���<e���s�[��`�w ?�����)�w�*����O��9�s9E���S��c�;_��_��� o���d�	���;���9�oa� g�ӀO0�r?���� �]���G��2O���0�L�_e��@�c�@���n�?f�@ϰ�6�K|;��<�2�x=������|���]~�]����	��3�0�)��e��������܏'<�#^	�^�O��c��@���_��fp	�<
tY����~7�~�&��8�����1�����I��\�߯�j�~����E��k�M����+(<��@���Q�?�����Sٿ~��zﵘ��)����s�}���Vh�\C��2ϛX��^�{�m��j�^g�پ�D�u?���y�����B�"��Z>G�7��W��#����_�o-:\�?;\��f�lE_����R��?�z?��	4f�/�5����J�V+��g}_z�-�8���s'�i�L�;�dN)�#�ש�G�n>�vp�ٶ�����7��6TE` xX&��wx��9���I�����I�xT��'�� LL(b&>������ĭ��[�bV��?Ůl���m~Dz|�Ȟ����Se㩲�T�x�l<��Oe�F<�~AA�lt|�X�?:Q�[%N�0Pm:�z��~��b��qU��⪔��]P��U2D«&�S���Tc�x�l<�e��2�Q�OK�Y��,���6u��Lجo�m�)�̢RK	����H>n���VM
�"�Y��KF���ʆQeè�haT��ʆPeC��!T��l՗3��n�/U������(�(�.a���o�"��Eƿ؋��Wpi�ȳ}��M��>���h�"�J�y���r'$%�^�����%���U���W��w%�KՏ��5�����2��z��!=�+��㳔�S�g=��f_��?E|��y�1~�<�M7>�E`�=E|�QN���Á���ej?��!ʻ�`;k7G�K��7�������ިg.󭆂����;���Vp�?o�?�D�02��y^^�M����?�f|���[����,�B��B������Z�Å���������M���8�1������	��y�]gˍ��������a���c_��3~~Yn�G���7���A����d��!����'8�/l�͊��&��%2�����
�����<����ﲫ�/Y�or�W/��-S��]�F��]P{�'�w%��Iz ��������I�l��e�����?iW!/����U���9x�$�Id���/�O�\98��0���������zn��=��p�c�Sě}���� �E>{��z̓π؂D,�cΈ�X��;���#�����t�=vȁ���%x���&�륭�²���5iO��6i��n�TK����NtKA��X�;P���ppo���*�m\�Ë���"g�Nΐ/��7s�3=��?O'����B�?�·;��]������8��S;_���3��o0v*�����1��������ss;�v.�v*�7	�vs;�r켖cg������4ݸ�(�lܧ��}���_
>4���l��~�ٸO�<���ڻઊ3���sCb�hF���XP�B��u�7�nh� ��
���`p��P�uL�B�:�hM��T�����G!D�cD�Z��z��$�#QIw���ww��P���e������{���ݳ���#阸ϧ!l�>���x�Y��>�#��i��}�Ep� �������s<����>�#����3�}�!����,Cp��������|�}���>?Dp�c����t���}6!�ϵ�S�;M����G��}1�s����}b>f�S�;Ȑ�vi�>?�!?r�)>LL���Y��> �����}.@p����
�ل�>;��:�y-���@p�7#��������a��,��|	�}@p�)��9����}��g���Gp����X�y!�����>"�O�}6"�ϫ����s+��܈�>Cp�� �ϧ���s7��|�}@p���g6��<�}�Dp���g9��\��>/Cp�u��}ވ�>7"���������8��|�}�8F����>3��.�4�_��C~�o��r<h� =����M��*օ���~�	t(�ǃS�t�"W�Qrb��K�O�-��'6���x��N)���L)	�߆��[��|0;���-�V���T�C���oZ�1y-��� i�g�5ho�e*�wS���S�_��#}�?����4_)��R�������h��P����Y��z=_�y�'|q��y5ܗ�F#v8��o冃�����1�OB������e�s}�"�������� e�4$����M-�PVZ��T\�˔q��_��cTy�X��5ֺD|�G��Y$͵j��an��vf��G^���
��S��#�UP�G�4�d$�ې�/@�_��7I{ڧx��駌��|[Z���ƱgZ�N�56�v��!�%�ܵ+V���5�`H���VT�s�u� ��7��iu]����=v��
�}"wE��'����C�ѫ*���Z���&�P��Buw�e�>��#r�6*�2���|�[R\R<���t�;����]d��Z��?�}��P�����*��M��zuH�#���%��o�vQ��g��բ}���`>_� c�9���tF+ru�w�"W����\��b�\�&��_T)ru�w�"W��Dǁ�Ć�Q����5�3�wg��}S�Q�F���R��X��{Sl�9�fUӻ���¬Jz�y�f�]�#<|������_�0����<�sfU����?eaV��5<��¬�쭡��y�[G�H��Yg�!:��vq!�Ծ\Oֳ�F�搢��y�-"�����d��Ѥ?飊�W/Ot���x�`Uu�s��T?���*�=ו#=����4���OM�.IL��^��P�&w��|�ǧ@��w�K}�!E�|�^�������%�s��Dho��CmT�)O�5��������\�(z��y��
�'|�>���C�����Y��%;Rt�����.ｚmz���G�5�B���,��C��1���!����T2ʯ��W��~���q&�.FEq7�(I,�f��^2��~��_��,5�9�NfK�8/�_�7D�k�!#�|#�S�dn�y�K��ǯq)��ɼ@%(���c�o�9~i��/�Ê���K*:����8j�iQo�z�/����$v~e���/����#le�����f�4�
����J\�a�~��\�<�,�<~y�ݵ9��?ٵr3+
����!��P����KiAb���?���h���RJ�J�_O���������z�pǪC���}����,>�_����/���C�9�Ay0�ϥ�U��?�G������b"y�#�s��^��N��}���#�U��s��@?E��s��;�����1�~������T?ѿf����fZoÑ����!�u�Ź�&+?-wկ����M֬H�/�Y��FgVd���Dd�Y��ԎA�"����xdb<2�<-����l^��tn��X$p�\���.p�\���}nMN��1د��
���7��W�qV�Y��!<V��Z�nX��7�>���V��1���}^u���u����(t��X�x���%�C�r��L�Tz���_�e�s�b�H�%�JUVL�G!,�-�,�����۩���"߃�Ǿ��#��M���Z�o�v���{�����93fL���3ɘ(����L�4ebY����Eu�hbE�'�0i������l;/+���2�i�$�Z���iΗ�����􉹃L�7���b��qH�O��o�_v!̖/9�4ÈHi���,��!���o�!�^B�!��Ki&48��!q���.��+C*�t�29�yb�C��ti.�9��H�~�^�,��!m��L�	��!�}j�28�����,�C�A*�o�sHoy�l]֟C����C��IsH�u��4�Y�3_�9��6����C�
��lI��&
�4Ü+��$��!}��9�_&8�4�d��f����[�.�Ui֖�C�Œ���!]�c�<��x�4�㐾�V8�Km�C��HsH3Kg��8��7pH��%�t��9����wڜCz�-9�����Qg��ҷ:�C���f��C�#[rHaKiv�8�12pH�r$�t�#9�g8�C�&�Cz�#9��ڜCz�-9��9��=��fo.pH�as�ݶ�~ۖ�
҇m�!��H�3�!=ґ����fx������u� �?w$��u��nw$�4�B��GrH3�R�!}���!}�#9��9>�a��qH?�x�]0��8��u4�w�C�}5��q4��4���3{�/8|���B�^#��H�c�aca,��0��pK0ca0��0��ªl��0
k,ùt;M��Lӽo�а�����x��x��8㺴1��	�(v|�(��;�(���{�C#�	���=�����ڸ��F`d��4�!�0�!>&����y[�6h�A[�ۺ�Kk�b~8@{����S�
��&?�-���E#��g����p����1Yvl9��m9�X�n��B�ҖN���|��5
]I�f[�W�v��U�ݪ��n��.����������zŧ�dq����r��?��?�&>]~��FY��d|�Oۗ��f�Zκ�5`�&^^1�u���~EK=)N�_M=��š�b����0�C#¯5��[�!`�g%�6D��q��D1����a����ͼ+h��Y�y'�������Hk@���p�nKH�أX 2�i����1�~�ϣ�-�k��my~S�;�ܦ.��<��\$��O�ʳ�L]�#�o��S�9V]�K�|�e�����<B��ʇH^]�G�}���<�.?M���姓������'�/ �>t��.?������3��,�]��ȇ"�a�|8"?�!�h���"ʴ�q�w���gI�;��qVL�����)~FI��w!�oA�Ww�9q$���nf;�	�I��] �3Η?"�5�{����rz��2�헐�#�ln/'��c�u>��G=�)!��%H:q?��_�o$?��� 7�y5O'�cX���{�	�k���I7�'��� 7��?��y�^B�)�Nf?�R�\�_>�ϴ���VY��I���r�_x�7-��=r��#�;�D�O��Sy�u&�7�����_��Ǐ�}F��m�<U ��B�o!I�/��˿�w�������+۟��M�_3�䫞`�s����8���}�M��-��]m��5���ֶ֖�+�kiJsg,r++W�.I󐹭�n-�k!>"�M6�ܓ�M�-u�ι�4Ե�%��&���Gr�s9��Ϛ�o��lkl\OU����BTם�(>o�;k�LƦ�K��f̞�xV�[/����%��.�,bĝ����y3�<
��N��T�0`�mi�wAD� y������f��8��@c�ҡW�)���c��z<qf�>�j���.�c���s�'��k��
N;��T�<�G��
H?Mc��7���H�ks����ot��[��E>n(���A��3�m�}��\si�M�me�����3����A��g��.���e�Ԟ��#&��E�F�2po�n���w�3�/����z���Z�_�5�Y)����#�{Z�g��\4K�ə�'������,��@=��Wݾ��F����o6��w`�w���ZC_����붿�p��������X�;��G̓�����/��~���'��nC_|϶N�?����D�o��՟3��8�alg�o�|3����}��B�(��������|�aC_��W���w������놾�~���f ��}1?���?o3�.����r����7���o_T�#����M�m^n���?C!}�\xN���OE���J����"���l��������_h�w���+A�1޿�K�#�͆�0���O��>9[?��G���a�Xvz�0�g��A��g����.p�\���.p�\�w��� ��L �  