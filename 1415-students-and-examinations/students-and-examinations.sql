-- SELECT S.student_id, S.student_name, Sbj.subject_name, count(*) as exam_count
-- FROM Students S
-- JOIN (
--     SELECT E.student_id, E.subject_name
--     FROM Examinations E
--     GROUP BY E.student_id, E.subject_name
-- ) E_grouped ON S.student_id = E_grouped.student_id
-- JOIN Subjects Sbj ON Sbj.subject_name = E_grouped.subject_name
-- GROUP BY S.student_id, Sbj.subject_name;


SELECT S.student_id , S.student_name , SBJ.subject_name, COUNT(E.subject_name) AS attended_exams
FROM Students S
JOIN Subjects SBJ
LEFT JOIN Examinations E 
ON S.student_id = E.student_id AND SBJ.subject_name = E.subject_name

GROUP BY S.student_id, SBJ.subject_name
ORDER BY S.student_id



-- SELECT S.student_id , S.student_name , E.subject_name, COUNT(*) AS attended_exams
-- FROM Examinations E , Students S
-- WHERE  S.student_id = E.student_id
-- GROUP BY S.student_id , E.subject_name
-- ORDER BY S.student_id